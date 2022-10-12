#include "TroopMember_A.h"

TroopMember_A::TroopMember_A(Location loc)
{
	m_Data.Score = 20;
	m_Data.Rect.Set(loc, 26, 20);
	m_Data.Imgs.Init(2, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 54, std::string("./Resources/TroopMember/A.png"));
	m_Data.DeathImgs.Init( 1, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 54, std::string("./Resources/TroopMember/A_Dead.png"));
}