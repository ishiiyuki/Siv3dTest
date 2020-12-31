#pragma once

# include <Siv3D.hpp> // OpenSiv3D v0.4.3
class Player
{


private:

	double playerSpeed = 55.0;

	Vec2 playerPos;

	Texture playerTexture;

	Array<Vec2>playerBullets;


public:

	Player();
	~Player();

};

