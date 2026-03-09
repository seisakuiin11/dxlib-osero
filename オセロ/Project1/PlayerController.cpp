#include "PlayerController.h"
#include "DxLib.h"

Player::Player()
{
	turn = 0;
}

Player::~Player()
{
}

/*** 初期化 ***/
void Player::Initialize() {
	// 1P 2P の考え
	turn = 1;
}

/*** ゲーム内処理 ***/
Vector2 Player::Process() {
	Vector2 vec(-1, -1);

	// プレイヤー入力
	if (GetMouse()->GetInputMouseDown(0)) vec = GetMouse()->GetMousePos();

	return vec;
}

/*** 描画 ***/
void Player::Disp() {
	if (turn < 0) return;
	Text::DispText(turn == 1 ? "プレイヤー：黒" : "プレイヤー：白", Vector2(1130, 125), Text::Left, 45);
}

int Player::GetTurn() {
	return turn;
}

void Player::SetTurn(int Turn) {
	turn = Turn;
}