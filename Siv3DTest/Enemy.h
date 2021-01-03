#pragma once

# include <Siv3D.hpp> // OpenSiv3D v0.4.3
# include"Unit.h"
class Enemy :
	public Unit
{


private:

	double mySpeed = 100.0;


public:

	Enemy();
	~Enemy();

	void Update(double deltaTime, bool& gameover);

	void Draw();

	
};

