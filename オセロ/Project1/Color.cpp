#include "OriginalClass.h"
#include "DxLib.h"

Color::Color(int r = 0, int g = 0, int b = 0)
{
	color = GetColor(r, g, b);
}

Color::~Color()
{
}

// êF ê›íË
int Color::Black() {
	return GetColor(0, 0, 0);
}
int Color::White() {
	return GetColor(255, 255, 255);
}
int Color::Red() {
	return GetColor(255, 0, 0);
}
int Color::Green() {
	return GetColor(0, 255, 0);
}
int Color::Blue() {
	return GetColor(0, 0, 255);
}
int Color::Orange() {
	return GetColor(255, 165, 0);
}
int Color::Yellow() {
	return GetColor(255, 255, 0);
}
int Color::Pink() {
	return GetColor(255, 192, 203);
}
int Color::Purple() {
	return GetColor(128, 0, 128);
}
int Color::Violet() {
	return GetColor(238, 130, 238);
}
int Color::Cyan() {
	return GetColor(0, 255, 255);
}
int Color::Lightblue() {
	return GetColor(173, 216, 230);
}
int Color::Lightgreen() {
	return GetColor(144, 238, 144);
}
int Color::Gray() {
	return GetColor(128, 128, 128);
}