#pragma once
#include "DxLib.h"
#include "OriginalClass.h"
#include "InputSystem.h"

class Directer
{
public:
	Directer();
	~Directer();

private:

public:
	virtual void Initialize();
	virtual int Process(int* flag);
	virtual void Disp();
};