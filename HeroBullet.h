#ifndef HEROBULLET_H_INCLUDED_
#define HEROBULLET_H_INCLUDED_

#include "Bullet.h"

class HeroBullet : public Bullet
{
public:
	HeroBullet(Location loc);
	virtual void Move();
};

#endif //HEROBULLET_H_INCLUDED_