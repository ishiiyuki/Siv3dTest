#pragma once
#include "Bullet.h"
class EnemyBullet :
    public Bullet
{

private:

public:

    EnemyBullet(Vec2 setPos) {
        pos = setPos;
        speed = 300.0;
    }
    ~EnemyBullet() {

    }

    bool BulletEnd() const {
        return pos.y > 700;
    }


    void Update(double deltaTime);

    virtual void Draw();

};

