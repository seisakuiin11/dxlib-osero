#include "TitleDirecter.h"

TitleDirecter::TitleDirecter()
{
	
}

TitleDirecter::~TitleDirecter()
{
}

/*** 初期化 ***/
void TitleDirecter::Initialize() {
	endUI.Initialize();
}

/*** ゲーム内処理 ***/
int TitleDirecter::Process(int* flag) {
	int scene = 0; // タイトルシーンIndex
	if (GetKey()->GetInputKeyUp(KEY_INPUT_SPACE) && !endUI.GetStateFlag()) scene = 1; // 次のシーンへ
	if (GetKey()->GetInputKeyUp(KEY_INPUT_ESCAPE)) endUI.ChangeState(); // UIを表示する

	// マウス操作
	if (GetMouse()->GetInputMouseUp(0)) {
		endUI.OnClick(GetMouse()->GetMousePos(), flag);
	}

	return scene;
}

/*** 描画 ***/
void TitleDirecter::Disp() {
	Text::DispText("オセロ", Vector2(WinData::Width / 2, 340), Text::Center, 80);
	Text::DispText("スペースキー スタート", Vector2(WinData::Width / 2, 500), Text::Center, 40);
	// 終了画面
	endUI.Disp();
}