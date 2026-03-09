/*** Header File ***/
#include "DxLib.h"
#include "Main.h"
#include "InputSystem.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);							// ウィンドウモードで起動
	SetWaitVSyncFlag(0);							// 垂直同期を切る
	if (DxLib_Init() == -1)							// ＤＸライブラリ初期化処理
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	/*** Window Init ***/
	SetWindowText("Reversi Game");						// ウィンドウのタイトル
	SetWindowInitPosition(WinData::PosX, WinData::PosY);// ウィンドウの位置
	SetGraphMode(WinData::Width, WinData::Height, 32);	// ウィンドウのサイズ
	SetBackgroundColor(255, 255, 255);					// ウィンドウの背景色
	SetDrawScreen(DX_SCREEN_BACK);						// 描画先画面を裏画面にする
	SetAlwaysRunFlag(FALSE);							// ウインドウ非アクティブ状態でも処理を続行する

	Initialize(); // 初期化
	Disp();		  // 表示

	/*** -------------- メインループ ------------------ ***/
	bool flag = true;
	while (flag && ProcessMessage() == 0)
	{
		// FPS
		fps.Update();
		// 入力デバイス 更新
		GetKey()->Update();
		GetMouse()->Update();
		// メイン処理
		flag = Process();
		// 描画
		Disp();
		fps.Wait();
	}

	DxLib_End();					// ＤＸライブラリ使用の終了処理

	return 0;						// ソフトの終了 
}

/*** 初期化 ***/
void Initialize() {
	key = new KeyBoard;
	mouse = new Mouse;
	// 各種初期化
	fps.SetFPS(WinData::FPS);
	Scene.Initialize(TITLE);
}

/*** ゲーム内処理 ***/
int Process() {
	int flag = 0;
	flag = Scene.Process();
	return flag;
}

/*** 描画 ***/
void Disp() {
	ClearDrawScreen(); // 画面の初期化

	// 各種描画処理
	Scene.Disp();
	fps.DrawFps(); // FPSの表示
	
	ScreenFlip(); // 裏画面の内容を表画面に反映
}