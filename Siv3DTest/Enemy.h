#pragma once

# include <Siv3D.hpp> // OpenSiv3D v0.4.3
class Enemy
{


private:

public:

	Enemy();
	~Enemy();

	//敵のランダム配置
	Vec2 GenerateEnemy();
};

