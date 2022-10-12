#include "TroopMember.h"

TroopMember::TroopMember() : m_Data()
{
	m_Data.Life = 1;
}

void TroopMember::Kill()
{
	m_Data.Death = true;
	m_Data.Count = 0;
	m_Data.Life--;
	m_Data.ImgIndex = 0;
	Utils::SoundPlay("EnemyDead", DX_PLAYTYPE_BACK, TRUE);
}

void TroopMember::Action()
{
	if(m_Data.GameOver) return;

	m_Data.Count++;

	if(m_Data.Death == true && m_Data.Count > 30) m_Data.GameOver = true;
}

void TroopMember::Move(Location loc)
{
	if(m_Data.Death == true || m_Data.GameOver == true) return;

	m_Data.Rect.Add(loc); 
}

void TroopMember::Draw()
{
	if(m_Data.GameOver) return;

	if(m_Data.Death == true)
		Utils::DrawImg(m_Data.DeathImgs.NowImgHandle(m_Data.Count), m_Data.Rect);
	else
		Utils::DrawImg(m_Data.Imgs.NowImgHandle(m_Data.Count), m_Data.Rect);
}
