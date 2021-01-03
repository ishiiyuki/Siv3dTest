#include "PlayerBullet.h"

void PlayerBullet::Update(double deltaTime)
{
	pos.y += deltaTime * -speed;
	Draw();
}

void PlayerBullet::Draw()
{
	Circle(pos, 8).draw(Palette::Orange);
}