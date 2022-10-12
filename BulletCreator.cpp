#include "BulletCreator.h"

Bullet* BulletCreator::Create(int type, Location loc)
{
	switch(type)
	{
		case Bullet::HERO:
			return new HeroBullet(loc);
			break;
		case Bullet::ENEMY:
			return new EnemyBullet(loc);
			break;
		default:
			return NULL;
			break;
	}
}
