#include "OriginalClass.h"
#include <math.h>

RigidBody2D::RigidBody2D()
{
	mass = 0;
	force = 0;
	underLine = 0;
	gravity = 0.0f;
	airDensity = 0.0f;
	drag = 0.0f;
}

RigidBody2D::~RigidBody2D()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="Mass">質量</param><param name="Force">力の方向と量</param>
/// <param name="UnderLine">最低ライン</param><param name="Gravity">重力(9.8f)</param>
void RigidBody2D::Initialize(int Mass, Vector2 Force, int UnderLine, float Gravity, float AirDensity, float Drag) {
	mass = Mass;
	force = Force;
	underLine = UnderLine;
	gravity = Gravity;
	airDensity = AirDensity;
	drag = Drag;
}

/// <summary>
/// 自由落下
/// </summary>
/// <param name="pos">セットしたオブジェクトのポジション</param>
void RigidBody2D::FreeFall(Vector2* pos) {
	if (pos->y > underLine && force.y == 0) return;
	force.y += gravity * mass / WinData::FPS; // 重量による減速
	// 空気抵抗 = 0.5 * 抗力係数 * 空気密度(kg/m3) * 断面積(m2) * (速度*速度)(m/s)
	float airDrag = 0.5 * drag * airDensity * 2.963 * (force.Magnitude() * force.Magnitude()); // 空気抵抗
	if (airDrag * airDrag > mass * gravity / drag) airDrag = sqrt(mass * gravity / drag);
	if (force.y < 0) force.y += airDrag / WinData::FPS;
	if (force.y > 40) force.y = 40;
	pos->x += force.x;
	pos->y += force.y;
	if (pos->y > underLine) { force.y = 0; pos->y = underLine; }
}

/// <summary>
/// 力を加える
/// </summary>
/// <param name="Force">加えたい力の方向と量</param>
void RigidBody2D::AddForce(Vector2 Force) {
	force.x += Force.x;
	force.y += Force.y;
	startVec = force;
}

/// <summary>
/// 力の設定
/// </summary>
/// <param name="Vel">設定したい力の方向と量</param>
void RigidBody2D::SetVelocity(Vector2 Vel) {
	force = Vel;
	startVec = force;
}