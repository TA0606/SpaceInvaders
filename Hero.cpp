#include "Hero.h"

Hero::Hero(Location loc)
{
	m_Data.Life = 2;
	m_Data.Rect.Set(loc, 32, 20);
	m_Data.Imgs.Init(1, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 64, std::string("./Resources/Hero/Hero.png"));
	m_Data.DeathImgs.Init( 1, 1, m_Data.Rect.W, m_Data.Rect.H, 0, 64, std::string("./Resources/Hero/Dead.png"));
}

Hero::~Hero(void){}

void Hero::Kill()
{
	Character::Kill();//基底
	Utils::SoundPlay("HeroDead", DX_PLAYTYPE_BACK, TRUE);
}

void Hero::Action()
{
	if(m_Data.GameOver) return;

	m_Data.Count++;
	m_Data.Shot = Utils::KeyDownCheck(KEY_INPUT_SPACE) > 0 && m_Data.Death == false ? true : false;//ショットするか

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
}

void Hero::Move()
{
	if(m_Data.Death == true || m_Data.GameOver == true) return;

	int x = 0;

	if(Utils::KeyDownCheck(KEY_INPUT_RIGHT) > 0) x = 2;
	if(Utils::KeyDownCheck(KEY_INPUT_LEFT) > 0) x = -2;

	RectEx check(m_Data.Rect);
	check.Add(x, 0, 0, 0);
	if(Utils::WithinLimits(check) == false) return;//境界チェック
	
	m_Data.Rect.Add(x, 0, 0, 0);
}