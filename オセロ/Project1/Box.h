#pragma once
#include "OriginalClass.h"

enum COMA
{
	Empty,
	Black,
	White
};

class Box
{
public:
	Box();
	~Box();

private:
	Vector2 pos;
	int width;
	int coma;
	bool isPut;

public:
	void Initialize(Vector2 Pos, int Width, int Coma);
	void Process();
	void Disp();
	void SetComa(int Coma);
	int GetComa();
	/*** 配置可能マスFlag ***/
	void SetIsPut(bool Flag);
	bool Collition(Vector2 cPos);
};