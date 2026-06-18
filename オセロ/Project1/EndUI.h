#pragma once
#include "OriginalClass.h"

/// <summary>
/// ゲーム終了確認UIクラス
/// </summary>
class EndUI
{
public:
	EndUI();
	~EndUI();

private:
	bool stateFlag;// UIを開いているか
	int width;		// UIの横幅
	int height;		// UIの縦幅
	Vector2 pos;	// UIの左上頂点座標
	int backColor;	// 背景色
	Btn yesBtn;		// ボタン Yes
	Btn noBtn;		// ボタン No
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 描画
	/// </summary>
	void Disp();
	/// <summary>
	/// クリック時の処理
	/// </summary>
	/// <param name="MousePos">クリックした場所</param>
	/// <param name="flag">ゲーム終了フラグ</param>
	void OnClick(Vector2 MousePos, int* flag);
	/// <summary>
	/// UIを開く
	/// </summary>
	void ChangeState();
	/// <summary>
	/// Yesボタンを押していた時の処理
	/// </summary>
	/// <param name="flag">ゲーム終了フラグ</param>
	void YesBtnProcess(int* flag);
	/// <summary>
	/// Noボタンを押したときの処理
	/// </summary>
	void NoBtnProcess();
	/// <summary>
	/// UIが表示されているか
	/// </summary>
	/// <returns></returns>
	bool GetStateFlag();
};