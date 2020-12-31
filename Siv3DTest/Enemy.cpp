#include "Enemy.h"



Vec2 Enemy::GenerateEnemy()
{
	return RandomVec2({ 50,750 }, -20);
}


Enemy::Enemy()
{

}

Enemy::~Enemy()
{


}