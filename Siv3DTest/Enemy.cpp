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

void Enemy::Update(double deltaTime, bool& gameover)
{
	pos.y += deltaTime * speed;

    if (pos.y > 700)
    {
        // 敵が画面外に出たらゲームオーバー
        //gameover = true;
    }
	Draw();
}

void Enemy::Draw()
{
	texture.resized(60).drawAt(pos);
}