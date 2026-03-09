#pragma once
#include "ComonDirecter.h"
#include "TitleDirecter.h"
#include "GameDirecter.h"

/// <summary>
/// シーンの状態
/// </summary>
enum SceneState
{
	TITLE,
	INGAME,
	MAXSCENE
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

private:
	int sceneState;
	Directer* scene[MAXSCENE];
	TitleDirecter title; // タイトルシーン
	GameDirecter inGame; // インゲームシーン
public:
	/// <summary>
	/// 各種シーンの初期化 最初のシーンを設定
	/// </summary>
	/// <param name="State">スタート時のシーン</param>
	void Initialize(SceneState State);
	/// <summary>
	/// メインループ処理
	/// </summary>
	/// <returns>0が帰ってきたらゲーム終了</returns>
	int Process();
	/// <summary>
	/// 描画
	/// </summary>
	void Disp();
};