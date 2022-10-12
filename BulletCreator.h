#ifndef BULLETCREATOR_H_INCLUDED_
#define BULLETCREATOR_H_INCLUDED_

#include "HeroBullet.h"
#include "EnemyBullet.h"

class BulletCreator
{
public:
	static Bullet* Create(int type, Location loc);
};

#endif //BULLETCREATOR_H_INCLUDED_