#include "OriginalClass.h"
#include "DxLib.h"

Fps::Fps()
{
	startTime = GetNowCount();
	count = 0;
	fps = 0;
	FPS = 0;
}

Fps::~Fps()
{
}

void Fps::SetFPS(int _FPS) {
	FPS = _FPS;
}
/// <summary>
/// 処理を開始する時間を取得
/// </summary>
void Fps::Update() {
	if (count == 0) startTime = GetNowCount();
	if (count == FPS) {
		int t = GetNowCount();
		fps = 1000.0f / ((t - startTime) / (float)FPS);
		count = 0;
		startTime = t;
	}
	count++;
}

/// <summary>
/// 指定したFPSになるように待つ
/// </summary>
void Fps::Wait() {
	int tookTime = GetNowCount() - startTime;
	int waitTime = count * 1000 / FPS - tookTime;

	if (waitTime > 0) Sleep(waitTime);
}

/// <summary>
/// FPSを左上に表示する
/// </summary>
void Fps::DrawFps() {
	SetFontSize(20);
	DrawFormatString(20, 50, Color::Black(), "FPS:%4.1f", fps);
}