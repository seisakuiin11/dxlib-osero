#include "Box.h"
#include "DxLib.h"

Box::Box()
{
	width = 0;
	coma = Empty;
	isPut = false;
}

Box::~Box()
{
}

/*** 初期化 ***/
void Box::Initialize(Vector2 Pos, int Width, int Coma) {
	pos = Pos;
	width = Width;
	coma = Coma;
}

/*** ゲーム内処理 ***/
void Box::Process() {

}

/*** 描画 ***/
void Box::Disp() {
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + width, Color::Green(), TRUE);
	if(isPut) DrawBox(pos.x, pos.y, pos.x + width, pos.y + width, Color::Yellow(), TRUE); //置けるマスをハイライト
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + width, Color::Black(), FALSE);
	if (coma == Empty) return;

	// 駒の描画
	int hwidth = width / 2;
	if (coma == Black) DrawCircle(pos.x + hwidth, pos.y + hwidth, hwidth - 6, Color::Black(), TRUE);
	else DrawCircle(pos.x + hwidth, pos.y + hwidth, hwidth - 6, Color::White(), TRUE);
}

/*** 駒のセット ***/
void Box::SetComa(int Coma) {
	coma = Coma;
}

/*** 駒の取得 ***/
int Box::GetComa() {
	return coma;
}

/*** 配置可能マス ***/
void Box::SetIsPut(bool Flag) {
	isPut = Flag;
}

bool Box::Collition(Vector2 cPos) {
	if (!isPut) return false;
	if (cPos.x < pos.x || cPos.x > pos.x + width) return false;
	if (cPos.y < pos.y || cPos.y > pos.y + width) return false;
	return true;
}