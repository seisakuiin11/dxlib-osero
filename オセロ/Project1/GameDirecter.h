#pragma once
#include "ComonDirecter.h"
#include "PlayerController.h"
#include "Board.h"

/// <summary>
/// ゲームシーン管理クラス
/// </summary>
class GameDirecter : public Directer
{
public:
	GameDirecter();
	~GameDirecter();
private:
	Player player;	// プレイヤークラス
	Board board;	// 盤面管理クラス
public:
	// 初期化
	void Initialize() override;
	// 毎フレーム処理 ゲーム終了：flag = 0 次のシーン番号を返す
	int Process(int* flag) override;
	// 描画
	void Disp() override;
};