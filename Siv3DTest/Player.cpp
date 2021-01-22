#include "Player.h"

Player::Player()
{
	pos = Vec2(400,500);

	texture = Texture(Emoji(U"🤖"));
	speed = mySpeed;
	
}

Player::~Player()
{

}
void Player::Update(double deltaTime)
{

	auto move = Vec2(KeyRight.pressed() - KeyLeft.pressed(), KeyDown.pressed() - KeyUp.pressed())
		.setLength(deltaTime * speed * (KeyShift.pressed() ? 0.5 : 1.0));
	pos.moveBy(move).clamp(Scene::Rect());

	Draw();
}

void Player::Draw()
{
	// 自機の描画
	texture.resized(80).flipped().drawAt(pos);
}

bool Player::MyHitCheck(Vec2 enemyBulletPos)
{
	if (enemyBulletPos.distanceFrom(pos) <= 20)
	{
		return true;
	}
	return false;
}