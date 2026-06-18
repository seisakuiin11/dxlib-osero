#pragma once
#include "ComonDirecter.h"
#include "EndUI.h"

/// <summary>
/// タイトルシーン管理クラス
/// </summary>
class TitleDirecter : public Directer
{
public:
	TitleDirecter();
	~TitleDirecter();
private:
	EndUI endUI; // ゲーム終了確認
public:
	// 初期化
	void Initialize() override;
	// 毎フレーム処理 ゲーム終了：flag = 0 次のシーン番号を返す
	int Process(int* flag) override;
	// 描画
	void Disp() override;
};