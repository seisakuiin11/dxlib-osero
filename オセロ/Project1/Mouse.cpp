#include "InputSystem.h"
#include "DxLib.h"

Mouse::Mouse()
{
	vec = Vector2(0, 0);
	vecOld = Vector2(0, 0);
	for (int i = 0; i < 8; i++) {
		mouseState[i] = 0;
		mouseStateOld[i] = 0;
	}
	mouseType[0] = MOUSE_INPUT_LEFT;
	mouseType[1] = MOUSE_INPUT_RIGHT;
	mouseType[2] = MOUSE_INPUT_MIDDLE;
	mouseType[3] = MOUSE_INPUT_4;
	mouseType[4] = MOUSE_INPUT_5;
	mouseType[5] = MOUSE_INPUT_6;
	mouseType[6] = MOUSE_INPUT_7;
	mouseType[7] = MOUSE_INPUT_8;
}

Mouse::~Mouse()
{
}

/// <summary>
/// マウスの更新処理
/// </summary>
void Mouse::Update() {
	// ポジション更新
	vecOld = vec;
	int x, y;
	GetMousePoint(&x, &y);
	vec.x = x; vec.y = y;
	// ボタン入力更新
	int date = GetMouseInput();
	for (int i = 0; i < 8; i++) {
		mouseStateOld[i] = mouseState[i]; // 過去
		mouseState[i] = date & mouseType[i]; // 現在
	}
}

/// <summary>
/// マウスのボタンが押されている間
/// </summary>
/// <param name="MouseType">0:LEFT 1:RIGHT 2:MIDDLE</param>
bool Mouse::GetInputMouse(int MouseType) {
	if (mouseState[MouseType] == 0) return false;
	return true;
}

/// <summary>
/// マウスのボタンが押された瞬間
/// </summary>
/// <param name="MouseType">0:LEFT 1:RIGHT 2:MIDDLE</param>
bool Mouse::GetInputMouseDown(int MouseType) {
	if (mouseState[MouseType] == 0) return false; // キーが押されていなければ
	if (mouseStateOld[MouseType] != 0) return false; // キーをすでに押していたら
	return true;
}

/// <summary>
/// マウスのボタンが放された瞬間
/// </summary>
/// <param name="MouseType">0:LEFT 1:RIGHT 2:MIDDLE</param>
bool Mouse::GetInputMouseUp(int MouseType) {
	if (mouseState[MouseType] != 0) return false; // キーが押されていれば
	if (mouseStateOld[MouseType] == 0) return false; // キーをもとから押していなければ
	return true;
}

/// <summary>
/// マウスカーソルの位置を返す
/// </summary>
Vector2 Mouse::GetMousePos() {
	return vec;
}

/// <summary>
/// マウスカーソルの移動量を返す
/// </summary>
Vector2 Mouse::GetMouseAxis() {
	return Vector2(vec.x - vecOld.x, vec.y - vecOld.y); //	一フレーム前との座標の差を返す
}