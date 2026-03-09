#pragma once
#include "ComonDirecter.h"
#include "PlayerController.h"
#include "Board.h"

class GameDirecter : public Directer
{
public:
	GameDirecter();
	~GameDirecter();
private:
	Player player;
	Board board;
public:
	void Initialize() override;
	int Process(int* flag) override;
	void Disp() override;
};