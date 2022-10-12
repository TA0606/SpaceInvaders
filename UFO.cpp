#include "UFO.h"

UFO::UFO(Location loc)
{
	m_Data.Life = 1;
	m_Data.Score = 300;//スコア高めにする
	m_Data.Rect.Set(loc, 40, 20);
	m_Data.Imgs.Init(1, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 64, std::string("./Resources/UFO/UFO.png"));
	m_Data.DeathImgs.Init( 1, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 64, std::string("./Resources/UFO/UFO_Dead.png"));
}

UFO::~UFO(void)
{
	Utils::SoundStop("UFOTheme");//変だが、生きていてかつクリアかゲームオーバーのときに再生を止めるために必要
}

void UFO::Kill()
{
	Character::Kill();//基底
	Utils::SoundPlay("EnemyDead", DX_PLAYTYPE_BACK, TRUE);
}

void UFO::Action()
{
	if(m_Data.Count == 0) Utils::SoundPlay("UFOTheme", DX_PLAYTYPE_LOOP, TRUE);

	m_Data.Count++;

	if(Utils::WithinLimits(Location(m_Data.Rect.X, m_Data.Rect.Y)) == false) m_Data.GameOver = true;

	if(m_Data.Death == true && m_Data.Count > 50)
	{
		if(m_Data.Life > 0)
		{
			m_Data.Count = 0;
			m_Data.Death = false;
		}
		else
		{
			m_Data.GameOver = true;
		}
	}

	if(m_Data.Death == true || m_Data.GameOver == true) Utils::SoundStop("UFOTheme");
}

void UFO::Move()
{
	if(m_Data.Death == true || m_Data.GameOver == true) return;

	m_Data.Rect.Add(2, 0, 0, 0);
}