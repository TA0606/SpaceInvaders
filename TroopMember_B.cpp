#include "TroopMember_B.h"

TroopMember_B::TroopMember_B(Location loc)
{
	m_Data.Score = 40;
	m_Data.Rect.Set(loc, 22, 22);
	m_Data.Imgs.Init(2, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 54, std::string("./Resources/TroopMember/B.png"));
	m_Data.DeathImgs.Init( 1, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 54, std::string("./Resources/TroopMember/B_Dead.png"));
}