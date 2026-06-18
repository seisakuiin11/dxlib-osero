#pragma once
#include "OriginalClass.h"

enum COMA
{
	Empty,
	Black,
	White
};

/// <summary>
/// 各マスを管理するクラス
/// </summary>
class Box
{
public:
	Box();
	~Box();

private:
	Vector2 pos; // マスの左上頂点座標
	int width;	 // マスの幅
	int coma;	 // 空白,黒,白
	bool isPut;	 // 置けるかどうか

public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="Pos"></param>
	/// <param name="Width"></param>
	/// <param name="Coma"></param>
	void Initialize(Vector2 Pos, int Width, int Coma);
	/// <summary>
	/// 描画
	/// </summary>
	void Disp();
	/// <summary>
	/// コマを設定する
	/// </summary>
	/// <param name="Coma">空白,黒,白</param>
	void SetComa(int Coma);
	/// <summary>
	/// コマの状態を取得
	/// </summary>
	/// <returns>空白,黒,白</returns>
	int GetComa();
	/// <summary>
	/// 配置可能マスFlag
	/// </summary>
	/// <param name="Flag">置けるかどうか</param>
	void SetIsPut(bool Flag);
	/// <summary>
	/// クリック位置との当たり判定
	/// </summary>
	/// <param name="cPos">クリック位置</param>
	/// <returns>当たったかどうか</returns>
	bool Collition(Vector2 cPos);
};