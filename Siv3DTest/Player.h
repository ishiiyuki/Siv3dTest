#pragma once

# include <Siv3D.hpp> // OpenSiv3D v0.4.3
# include"Unit.h"
class Player :
	public Unit
{


private:

	//double mySpeed = 55.0;

	//Vec2 myPos;

	//Texture myTexture;


public:

	Player();
	~Player();

	//移動
	void Move();

	//ショット
	void Shot();

};

