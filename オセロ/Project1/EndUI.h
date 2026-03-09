#pragma once
#include "OriginalClass.h"

class EndUI
{
public:
	EndUI();
	~EndUI();

private:
	bool stateFlag;
	int width;
	int height;
	Vector2 pos;
	int backColor;
	Btn yesBtn;
	Btn noBtn;
public:
	void Initialize();
	void Process();
	void Disp();
	void OnClick(Vector2 MousePos, int* flag);
	void ChangeState();
	bool CheckState();
	void YesBtnProcess(int* flag);
	void NoBtnProcess();
	bool GetStateFlag();
};