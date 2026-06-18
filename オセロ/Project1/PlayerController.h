#pragma once
#include "OriginalClass.h"
#include "InputSystem.h"

class Player
{
public:
	Player();
	~Player();

private:
	int turn; // 1P or 2P

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	/// <returns>クリックした位置</returns>
	Vector2 Process();
	/// <summary>
	/// 描画
	/// </summary>
	void Disp();
	/// <summary>
	/// 現在のプレイヤー(1Por2P)を返す
	/// </summary>
	/// <returns>1P or 2P</returns>
	int GetTurn();
	/// <summary>
	/// 現在のプレイヤーを設定 (手番の変更)
	/// </summary>
	/// <param name="Turn">プレイヤー番号</param>
	void SetTurn(int Turn);
};