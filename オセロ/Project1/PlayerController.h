#pragma once
#include "OriginalClass.h"
#include "InputSystem.h"

class Player
{
public:
	Player();
	~Player();

private:
	int turn;

public:
	void Initialize();
	Vector2 Process();
	void Disp();
	int GetTurn();
	void SetTurn(int Turn);
};