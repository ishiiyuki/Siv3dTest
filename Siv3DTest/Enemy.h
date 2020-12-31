#pragma once

# include <Siv3D.hpp> // OpenSiv3D v0.4.3
class Enemy
{


private:

	double mySpeed = 100.0;

	Texture myTexture;

	Vec2 myPos;

public:

	Enemy();
	~Enemy();

	//敵のランダム配置
	Vec2 GenerateEnemy();
};

