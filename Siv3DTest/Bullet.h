#pragma once

# include <Siv3D.hpp> // OpenSiv3D v0.4.3
class Bullet
{

private:

protected:
	Vec2 pos;

	double speed;

	double spawnTime;



public:


	Bullet() {

	}
	~Bullet() {

	}

	Vec2 GetPos()
	{
		return pos;
	}

	virtual void Update(double deltaTime) = 0;

	virtual void Draw() = 0;

};

