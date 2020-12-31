#include "Player.h"

Player::Player()
{
	myPos = Vec2(400,500);

	myTexture = Texture(Emoji(U"🤖"));
}

Player::~Player()
{

}

