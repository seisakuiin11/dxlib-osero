#pragma once
#include "OriginalClass.h"
#include "SceneManager.h"

/*** システム設定 ***/
//#define DEF_SOUND_VALID			// サウンド有効

SceneManager Scene;
Fps fps;
KeyBoard* key = nullptr;
KeyBoard* GetKey() { return key; }
Mouse* mouse = nullptr;
Mouse* GetMouse() { return mouse; }

void Initialize();
int Process();
void Disp();