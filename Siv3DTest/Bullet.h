#pragma once

# include <Siv3D.hpp> // OpenSiv3D v0.4.3
class Bullet
{

private:
	Vec2 Pos;

	double Speed;
	
	double SpawnTime;

	double ShotCoolTime;

	double ShotTimer = 0.0;
public:


	Bullet();
	~Bullet();

};

