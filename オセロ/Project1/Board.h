#pragma once
#include "Box.h"

class Board
{
public:
	Board();
	~Board();

private:
	Vector2 pos;
	int width;
	int height;
	Box masu[8][8];
	int blComa; // 黒駒の数
	int whComa; // 白駒の数
	bool endFlag; // 試合終了
	bool putFlag; // おける場所があるか
	bool resultFlag; // リザルト表示
	float time = 0;

public:
	void Initialize();
	int Process(int Player);
	void Disp();
	/*** 設置可能マスの確認 ***/
	void Check(int Player);
	/*** 駒の設置 ***/
	int Put(int Player, Vector2 cPos);
	/*** 駒の数を計算する ***/
	void Count();
	bool GetEndFlag();
};