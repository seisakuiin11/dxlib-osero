#pragma once
#include "Box.h"

/// <summary>
/// 盤面管理クラス
/// </summary>
class Board
{
public:
	Board();
	~Board();

private:
	Vector2 pos;	 // 盤面の左上頂点座標
	int width;		 // 盤面全体の横幅
	int height;		 // 盤面全体の縦幅
	Box masu[8][8];	 // 各マス
	int blComa;		 // 黒駒の数
	int whComa;		 // 白駒の数
	bool endFlag;	 // 試合終了
	bool putFlag;	 // おける場所があるか
	bool resultFlag; // リザルト表示
	float time = 0;	 // 経過時間用

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	/// <param name="Player">手番 黒or白</param>
	/// <returns>次の手番プレイヤー</returns>
	int Process(int Player);
	/// <summary>
	/// 描画
	/// </summary>
	void Disp();
	/// <summary>
	/// 設置可能マスの確認
	/// </summary>
	/// <param name="Player">手番</param>
	void Check(int Player);
	/// <summary>
	/// 駒の設置
	/// </summary>
	/// <param name="Player">手番</param>
	/// <param name="cPos">クリックした場所</param>
	/// <returns>次の手番プレイヤー</returns>
	int Put(int Player, Vector2 cPos);
	/// <summary>
	/// 駒の数を計算する
	/// </summary>
	void Count();
	/// <summary>
	/// ゲームセット
	/// </summary>
	/// <returns>終了した</returns>
	bool GetEndFlag();
};