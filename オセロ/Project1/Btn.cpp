#include "OriginalClass.h"
#include "DxLib.h"

Btn::Btn()
{
	width = 0;
	height = 0;
	size = 0;
	color = 0;
	highlightColor = -1;
}

Btn::~Btn()
{
}

/*** èâä˙âª ***/
void Btn::Initialize(int Width, int Height, int Size, Vector2 Pos, Vector2 ShiftTextPos, int _Color, std::string _text, int HighlightColor) {
	width = Width;
	height = Height;
	pos = Pos;
	color = _Color;
	highlightColor = HighlightColor;
	Pos.x += ShiftTextPos.x;
	Pos.y += ShiftTextPos.y;
	text.Initialize(_text, Pos, Text::Center, Size);
}

/*** ï`âÊ ***/
void Btn::Disp() {
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, color, TRUE);
	text.Disp();
	if (highlightColor == -1) return;
}

/*** ìñÇΩÇËîªíË ***/
bool Btn::OnCollition(Vector2 mousePos) {
	if (mousePos.x < pos.x || mousePos.x > pos.x + width) return false;
	if (mousePos.y < pos.y || mousePos.y > pos.y + height) return false;
	return true;
}