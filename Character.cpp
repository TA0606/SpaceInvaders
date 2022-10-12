#include "Character.h"

void Character::Kill()
{
	m_Data.Death = true;
	m_Data.Count = 0;
	m_Data.Life--;
	m_Data.ImgIndex = 0;
}

void Character::Draw()
{
	if(m_Data.GameOver) return;

	if(m_Data.Death == true)
		Utils::DrawImg(m_Data.DeathImgs.NowImgHandle(m_Data.Count), m_Data.Rect);
	else
		Utils::DrawImg(m_Data.Imgs.NowImgHandle(m_Data.Count), m_Data.Rect);
}