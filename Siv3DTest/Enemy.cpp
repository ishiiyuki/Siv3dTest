#include "Enemy.h"





Enemy::Enemy()
{
	speed = mySpeed;
	texture = Texture(Emoji(U"👾"));
	pos = RandomVec2({ 50, 750 }, -20);
}

Enemy::~Enemy()
{


}

void Enemy::Update(double deltaTime)
{
	pos.y += deltaTime * speed;
}

void Enemy::Draw()
{
	texture.resized(60).drawAt(pos);
}