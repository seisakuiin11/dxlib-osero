#include "InputSystem.h"
#include "DxLib.h"

KeyBoard::KeyBoard()
{
	for (int i = 0; i < 256; i++) {
		keyState[i] = 0;
		keyBuf[i] = 0;
		keyBufOld[i] = 0;
	}
}

KeyBoard::~KeyBoard()
{
}

/// <summary>
/// キーの更新処理
/// </summary>
void KeyBoard::Update() {
	// 過去の状態をコピー
	for (int i = 0; i < BUFFER_SIZE; i++) { keyBufOld[i] = keyBuf[i]; }
	// 現在の状態を取得
	GetHitKeyStateAll(keyBuf);
}

/// <summary>
/// キーが押されている間
/// </summary>
bool KeyBoard::GetInputKey(int KeyType) {
	if (keyBuf[KeyType] == 1) return true;
	return false;
}

/// <summary>
/// キーが押された瞬間
/// </summary>
bool KeyBoard::GetInputKeyDown(int KeyType) {
	if (keyBuf[KeyType] == 1 && keyBufOld[KeyType] == 0) return true;
	return false;
}

/// <summary>
/// キーが放された瞬間
/// </summary>
bool KeyBoard::GetInputKeyUp(int KeyType) {
	if (keyBuf[KeyType] == 0 && keyBufOld[KeyType] == 1) return true;
	return false;
}