#include "HeroBullet.h"

HeroBullet::HeroBullet(Location loc)
{
	m_Type = Bullet::HERO;
	m_Rect.Set(loc, 4, 12);
	m_Imgs.Init(1, 1, m_Rect.W, m_Rect.H, 0, 64, std::string("./Resources/Bullet/HeroBullet.png"));
	Utils::SoundPlay("HeroShot", DX_PLAYTYPE_BACK, TRUE);
}

void HeroBullet::Move()
{
	Bullet::Move();
	m_Rect.Add(0, -4, 0, 0);
}