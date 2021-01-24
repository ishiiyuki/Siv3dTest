#pragma once
#include "Bullet.h"
#include "Enemy.h"
class HomingBullet :
    public Bullet
{

private:
    Vec2 shotStartPos;

    Vec2 shotEndPos;

    Vec2 shotStartVec;

    Vec2 shotEndVec;

    Enemy targetEnemy;

    double moveTime;

public:

    HomingBullet(Vec2 setPos, Vec2 svec, Enemy _targetEnemy) {
        pos = setPos;
        speed = 10.0;
        shotStartPos = setPos;
        shotStartVec = svec;
        targetEnemy = _targetEnemy;

        shotEndPos = targetEnemy.pos;
        shotEndVec = shotEndPos.movedBy(-200, 200);
        moveTime = 0;
    }
    ~HomingBullet() {

    }

    bool BulletEnd() const {
        return pos.y < -48;
    }


    void Update(double deltaTime);

    void Draw();

    Vec2 HermitLerp(Vec2 s, Vec2 e, Vec2 svec, Vec2 evec, float t);
};

