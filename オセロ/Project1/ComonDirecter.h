#pragma once
#include "DxLib.h"
#include "OriginalClass.h"
#include "InputSystem.h"

/// <summary>
/// 各シーンを管理するクラス
/// </summary>
class Directer
{
public:
	Directer();
	~Directer();

private:

public:
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize();
	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	/// <param name="flag">ゲームを続けるか 0でゲーム終了</param>
	/// <returns>次のシーン</returns>
	virtual int Process(int* flag);
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Disp();
};