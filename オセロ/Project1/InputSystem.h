#pragma once
#include "OriginalClass.h"

#define BUFFER_SIZE	256 // キー入力

/// <summary>
/// キーボード入力関数
/// </summary>
class KeyBoard
{
public:
	KeyBoard();
	~KeyBoard();
private:
	int keyState[BUFFER_SIZE];
	char keyBuf[BUFFER_SIZE];
	char keyBufOld[BUFFER_SIZE];
public:
	/// <summary>
	/// キーの更新処理
	/// </summary>
	void Update();
	/// <summary>
	/// キーが押されている間
	/// </summary>
	bool GetInputKey(int KeyType);
	/// <summary>
	/// キーが押された瞬間
	/// </summary>
	bool GetInputKeyDown(int KeyType);
	/// <summary>
	/// キーが放された瞬間
	/// </summary>
	bool GetInputKeyUp(int KeyType);
};
KeyBoard* GetKey();

/// <summary>
/// マウス入力関数
/// </summary>
class Mouse
{
public:
	Mouse();
	~Mouse();
private:
	Vector2 vec;
	Vector2 vecOld;
	int mouseState[8];
	int mouseStateOld[8];
	int mouseType[8];
public:
	/// <summary>
	/// マウスの更新処理
	/// </summary>
	void Update();
	/// <summary>
	/// マウスのボタンが押されている間
	/// </summary>
	/// <param name="MouseType">0:LEFT 1:RIGHT 2:MIDDLE</param>
	bool GetInputMouse(int MouseType);
	/// <summary>
	/// マウスのボタンが押された瞬間
	/// </summary>
	/// <param name="MouseType">0:LEFT 1:RIGHT 2:MIDDLE</param>
	bool GetInputMouseDown(int MouseType);
	/// <summary>
	/// マウスのボタンが放された瞬間
	/// </summary>
	/// <param name="MouseType">0:LEFT 1:RIGHT 2:MIDDLE</param>
	bool GetInputMouseUp(int MouseType);
	/// <summary>
	/// マウスカーソルの位置を返す
	/// </summary>
	Vector2 GetMousePos();
	/// <summary>
	/// マウスカーソルの移動量を返す
	/// </summary>
	Vector2 GetMouseAxis();
};
Mouse *GetMouse();