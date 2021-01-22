#include "Unit.h"


bool Unit::MyHitCheck(Vec2 _bulletPos, double _r)
{
	const Circle myHitCircle(pos, _r);
    if (myHitCircle.intersects(_bulletPos))
    {
        return true;
    }
	return false;
}