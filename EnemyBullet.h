#ifndef ENEMYBULLET_H_INCLUDED_
#define ENEMYBULLET_H_INCLUDED_

#include "Bullet.h"

class EnemyBullet : public Bullet
{
public:
	EnemyBullet(Location loc);
	virtual void Move();
};

#endif //ENEMYBULLET_H_INCLUDED_