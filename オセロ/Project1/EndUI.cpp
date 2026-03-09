#include "EndUI.h"
#include "DxLib.h"

EndUI::EndUI() {
	stateFlag = false;
	width = 0;
	height = 0;
	backColor = 0;
}

EndUI::~EndUI()
{
}

/*** 初期化 ***/
void EndUI::Initialize() {
	width = 860;
	height = 420;
	pos = Vector2(350, 170);
	backColor = Color::Lightgreen();
	yesBtn.Initialize(240, 100, 40, Vector2(pos.x+70, pos.y+260), Vector2(120,30), Color::Yellow(), "はい");
	noBtn.Initialize(240, 100, 40, Vector2(pos.x+540, pos.y+260), Vector2(120,30), Color::Yellow(), "いいえ");
}

/*** ゲーム内処理 ***/
void EndUI::Process() {

}

/*** 描画 ***/
void EndUI::Disp() {
	if (!stateFlag) return;
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, backColor, TRUE);
	Text::DispText("ゲームを終了して\nデスクトップに戻りますか？", Vector2(pos.x + (width / 2), pos.y + 100), Text::Center);
	yesBtn.Disp();
	noBtn.Disp();
}

/*** クリック時の処理 ***/
void EndUI::OnClick(Vector2 MousePos, int* flag) {
	if (!stateFlag) return;
	if (yesBtn.OnCollition(MousePos)) YesBtnProcess(flag);
	if (noBtn.OnCollition(MousePos)) NoBtnProcess();
}

/*** UIを開く ***/
void EndUI::ChangeState() {
	stateFlag = !stateFlag;
}

/*** フラグ取得 ***/
bool EndUI::CheckState() {
	return stateFlag;
}

/*** ボタンクリック時の処理 ***/
void EndUI::YesBtnProcess(int* flag) {
	*flag = 0;
	stateFlag = false;
}
void EndUI::NoBtnProcess() {
	stateFlag = false;
}

/*** UIが表示されているか ***/
bool EndUI::GetStateFlag() {
	return stateFlag;
}