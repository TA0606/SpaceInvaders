#include "TroopMember_C.h"

TroopMember_C::TroopMember_C(Location loc)
{
	m_Data.Score = 10;
	m_Data.Rect.Set(loc, 28, 20);
	m_Data.Imgs.Init(2, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 54, std::string("./Resources/TroopMember/C.png"));
	m_Data.DeathImgs.Init( 1, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 54, std::string("./Resources/TroopMember/C_Dead.png"));
}