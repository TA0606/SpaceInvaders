#include "Bullet.h"

void Bullet::Action()
{
	m_Count++;
	if(Utils::WithinLimits(Location(m_Rect.CenterX(), m_Rect.CenterY())) == false) m_Delete = true;
}

void Bullet::Move()
{
	if(m_Delete) return;
}

void Bullet::Draw()
{
	if(m_Delete) return;

	Utils::DrawImg(m_Imgs.NowImgHandle(m_Count), m_Rect);
}