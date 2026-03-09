#pragma once
#include "ComonDirecter.h"
#include "EndUI.h"

class TitleDirecter : public Directer
{
public:
	TitleDirecter();
	~TitleDirecter();
private:
	EndUI endUI;
public:
	void Initialize() override;
	int Process(int* flag) override;
	void Disp() override;
};