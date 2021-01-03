#include "EnemyBullet.h"
void EnemyBullet::Update(double deltaTime)
{
	pos.y += deltaTime * speed;
	Draw();
}

void EnemyBullet::Draw()
{
	Circle(pos, 4).draw(Palette::White);
}