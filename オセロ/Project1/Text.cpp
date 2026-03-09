#include "OriginalClass.h"
#include "DxLib.h"
#include <sstream>
#include <vector>

Text::Text()
{
}

Text::~Text()
{
}

void Text::Initialize(std::string _text, Vector2 _pos, PosType _posType, int _size, int _underSpace, int _color) {
	text = _text;
	pos = _pos;
	posType = _posType;
	size = _size;
	underSpace = _underSpace;
	color = _color;
}

void Text::Disp() {
	SetFontSize(size); // フォントサイズ
	std::istringstream iss(text); // 文字列をストリームへ
	std::string str;
	std::vector<std::string> texts; // 配列 List型のようなもの

	// 改行ことに文字列を格納
	while (std::getline(iss, str)) {
		texts.push_back(str);
	}
	// 文字列の描画
	int count = 0;
	for (const auto& tx : texts) {
		int textWidth = GetDrawStringWidth(tx.c_str(), -1);
		DrawString(pos.x - (textWidth * posType / 2), pos.y + count * (size + 5), tx.c_str(), color);
		count++;
	}
}

void Text::DispText(std::string text, Vector2 pos, PosType posType, int size, int underSpace, int color) {
	SetFontSize(size); // フォントサイズ
	std::istringstream iss(text); // 文字列をストリームへ
	std::string str;
	List<std::string> texts;

	// 改行ことに文字列を格納
	while (std::getline(iss,str)) {
		texts.Add(str);
	}
	// 文字列の描画
	int count = 0;
	for (int i = 0; i < texts.Count(); i++) {
		int textWidth = GetDrawStringWidth(texts[i].c_str(), -1);
		DrawString(pos.x - (textWidth * posType / 2), pos.y + count*(size+underSpace), texts[i].c_str(), color);
		count++;
	}
	
}