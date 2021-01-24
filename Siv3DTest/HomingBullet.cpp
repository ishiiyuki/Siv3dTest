#include "HomingBullet.h"
void HomingBullet::Update(double deltaTime)
{
	moveTime += Scene::DeltaTime();
	shotEndPos = targetEnemy.pos;

	pos = HermitLerp(shotStartPos, shotEndPos,shotStartVec,shotEndVec, moveTime);
	Draw();
}

void HomingBullet::Draw()
{
	Circle(pos, 8).draw(Palette::Green);
}


Vec2 HomingBullet::HermitLerp(Vec2 s, Vec2 e, Vec2 svec, Vec2 evec, float t)
{
	Vec2 _Pos;

	_Pos = (((t - 1) * (t - 1)) * (2 * t + 1) * s) + ((t * t) * (3 - 2 * t) * e) + ((1 - (t * t)) * t * svec) + ((t - 1) * (t * t) * evec);

	return _Pos;
}