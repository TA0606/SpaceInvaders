#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Location loc)
{
	m_Type = Bullet::ENEMY;
	m_Rect.Set(loc, 4, 12);
	m_Imgs.Init(1, 1, m_Rect.W, m_Rect.H, 0, 64, std::string("./Resources/Bullet/EnemyBullet.png"));
	Utils::SoundPlay("EnemyShot", DX_PLAYTYPE_BACK, TRUE);
}

void EnemyBullet::Move()
{
	Bullet::Move();
	m_Rect.Add(0, 4, 0, 0);
}
