#include "OriginalClass.h"
#include <math.h>

Vector2::Vector2(int X, int Y)
{
	x = X;
	y = Y;
}
Vector2::~Vector2()
{
}

/// <summary>
/// ƒxƒNƒgƒ‹‚Ì—Ê‚ð•Ô‚·
/// </summary>
float Vector2::Magnitude() {
	float mas = (x * x) + (y * y);
	return sqrt(mas);
}

/// <summary>
/// Vector2(0,0)‚ð•Ô‚·
/// </summary>
Vector2 Vector2::zero() {
	return Vector2(0,0);
}
/// <summary>
/// Vector2(0,-1)‚ð•Ô‚·
/// </summary>
Vector2 Vector2::Up() {
	return Vector2(0, -1);
}
/// <summary>
/// Vector2(0,1)‚ð•Ô‚·
/// </summary>
Vector2 Vector2::Down() {
	return Vector2(0, 1);
}
/// <summary>
/// Vector2(-1,0)‚ð•Ô‚·
/// </summary>
Vector2 Vector2::Left() {
	return Vector2(-1, 0);
}
/// <summary>
/// Vector2(1,0)‚ð•Ô‚·
/// </summary>
Vector2 Vector2::Right() {
	return Vector2(1, 0);
}