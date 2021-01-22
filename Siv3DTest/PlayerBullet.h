#pragma once
#include "Bullet.h"
class PlayerBullet :
    public Bullet
{
private:

public:

    PlayerBullet(Vec2 setPos) {
        pos = setPos;
        speed = 500.0;
    }
    ~PlayerBullet() {

    }

    bool BulletEnd() const {
        return pos.y < -48;
    }


    void Update(double deltaTime) ;

    void Draw() ;
};

