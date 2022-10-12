#include "Game.h"
int Game::m_Score = 0;

Game::Game(int stage) : m_Count(0), m_StageNum(0), m_HighScore(0)
{
	Location troops_loc[5] = { Point(10, 50), Point(10, 120), Point(10, 160), Point(10, 200), Point(10, 250) };
	Location pillbox_loc[4] = { Point(80, 400), Point(220, 400), Point(360, 400), Point(500, 400) };
	m_StageNum = stage;
	if(m_StageNum == 0) m_Score = 0;
	RectEx cr(Utils::ClientRectEx());
	m_Hero.reset( new Hero(Point(cr.CenterX(), cr.Bottom() - 32)) );
	m_EnemyTroops.reset( new EnemyTroops(troops_loc[m_StageNum], cr.Bottom() - 32) );

	for(int i = 0; i < 4; i++)
		m_Pillboxs.push_back( shared_ptr<Pillbox>( new Pillbox(pillbox_loc[i])));

	ifstream ifs("./Resources/Score/HighScore.txt");
	ifs >> m_HighScore;
	ifs.close();

	SetFontSize(18);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
}

Game::~Game()
{
	if(m_HighScore < m_Score)
	{
		ofstream ofs("./Resources/Score/HighScore.txt", std::ios::out | std::ios::trunc);
		ofs << m_Score;
		ofs.close();
	}
}

void Game::Refresh()
{
	Update();
	Collision();
	Shot();
	Action();
	Move();
	Draw();
}

void Game::Update()
{
	m_Count++;
	m_BulletManager.Refresh();

	if(m_EnemyTroops->CheckInvasion() || m_Hero->GameIsOver())
	{
		m_End = true;
		m_NextSequence = Sequence::GAMEOVER;
	}

	if(m_EnemyTroops->IsAnnihilation())
	{
		m_End = true;
		m_NextSequence = m_StageNum < 4 ? Sequence::CLEAR : Sequence::ENDING;
	}

	SpecialUpdate();
}

void Game::Shot()
{
	if(m_Hero->GetShotFlag()) 
	{
		if(m_BulletManager.GetHeroBullet() == -1)//ヒーローショットが存在していなかったら作成
		{
			Location loc(m_Hero->GetRect().CenterX(), m_Hero->GetRect().CenterY());
			m_BulletManager.Create(Bullet::HERO, loc);
		}
	}

	for(int i = 0, size = m_EnemyTroops->Length(); i < size; i++)
	{
		if(m_EnemyTroops->GetShotFlag(i))
		{
			Location loc(m_EnemyTroops->GetRect(i).CenterX(), m_EnemyTroops->GetRect(i).CenterY());
			m_BulletManager.Create(Bullet::ENEMY, loc);
		}
	}
}

void Game::Action()
{
	m_Hero->Action();
	if(m_UFO != NULL) m_UFO->Action();
	m_EnemyTroops->Action();
	m_BulletManager.Action();
}

void Game::Move()
{
	m_Hero->Move();
	if(m_UFO != NULL)m_UFO->Move();
	m_EnemyTroops->Move();
	m_BulletManager.Move();
}

void Game::Draw()
{
	for(int i = 0, size = m_Pillboxs.size(); i < size; i++)
		m_Pillboxs[i]->Draw();

	m_Hero->Draw();
	if(m_UFO != NULL)m_UFO->Draw();
	m_EnemyTroops->Draw();
	m_BulletManager.Draw();
	DrawFormatString( 0, 0,  GetColor( 255 , 255 , 255 ) , "SCORE  %05d      LIVES  %02d      HIGH SCORE  %05d", m_Score, m_Hero->GetLife(), m_HighScore ) ;
}

void Game::Collision()
{
	Judge_Hero_And_EnemyBullet();
	Judge_Enemy_And_HeroBullet();
	Judge_Enemy_And_Pillbox();
	Judge_Pillbox_And_Bullet();
}

void Game::SpecialUpdate()
{
	if(m_Count % 2500 == 0) m_UFO.reset(new UFO(Location(0, 30)) );
}

void Game::Judge_Hero_And_EnemyBullet()
{
	for(int i = 0, size = m_BulletManager.Length(); i < size; i++)
	{
		if(m_BulletManager.GetType(i) == Bullet::ENEMY && Utils::Collision(m_Hero->GetRect(), m_BulletManager.GetRect(i)))
		{
			m_Hero->Kill();
			m_BulletManager.Delete(i);
			break;
		}
	}
}

void Game::Judge_Enemy_And_HeroBullet()
{
	int h_index = m_BulletManager.GetHeroBullet();
	if(h_index != -1)
	{
		if(m_UFO != NULL && !m_UFO->IsDead() && Utils::Collision(m_UFO->GetRect(), m_BulletManager.GetRect(h_index))) //UFOのチェック
		{
			m_UFO->Kill();
			m_BulletManager.Delete(h_index);
			m_Score += m_UFO->GetScore();
		}

		for(int z = 0, size = m_EnemyTroops->Length(); z < size; z++)//敵軍のチェック
		{
			if(!m_EnemyTroops->IsDead(z) && Utils::Collision(m_EnemyTroops->GetRect(z), m_BulletManager.GetRect(h_index)))
			{
				m_Score += m_EnemyTroops->GetScore(z);
				m_EnemyTroops->Kill(z);
				m_BulletManager.Delete(h_index);
				break;
			}
		}
	}
}

void Game::Judge_Enemy_And_Pillbox()
{
	for(int i = 0, size = m_EnemyTroops->Length(); i < size; i++)
	{
		if(m_EnemyTroops->IsDead(i) == false) PillboxCollision(m_EnemyTroops->GetRect(i), false);
	}
}

void Game::Judge_Pillbox_And_Bullet()
{
	for(int i = 0, size = m_BulletManager.Length(); i < size; i++)
	{
		if(PillboxCollision(m_BulletManager.GetRect(i), true) == true) m_BulletManager.Delete(i);
	}
}

bool Game::PillboxCollision(RectEx r, bool bullet)
{
	bool collision = false;

	for(int z = 0, p_size = m_Pillboxs.size(); z < p_size && collision == false; z++)
	{
		collision = m_Pillboxs[z]->Collision(r, bullet);
	}

	return collision;
}
