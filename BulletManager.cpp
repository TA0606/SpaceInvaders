#include "BulletManager.h"

BulletManager::BulletManager(void) : m_Bullets()
{
}

int BulletManager::GetHeroBullet()
{
	for(int i = 0, size = m_Bullets.size(); i < size; i++)
	{
		if(m_Bullets[i]->GetType() == Bullet::HERO) return i;
	}

	return -1;//Ç±Ç±Ç‹Ç≈óàÇΩÇÁÉqÅ[ÉçÅ[ÇÃíeÇÕÇ»Ç¢
}

bool BulletManager::IsEmpty(int index)
{
	bool empty = true;

	if(index < static_cast<int>(m_Bullets.size()) &&
		index >= 0 &&
		m_Bullets[index]->GetDeleteFlg() == false)
	{
		empty = false;
	}

	return empty;
}

void BulletManager::Create(int type, Location loc)
{
	m_Bullets.push_back(shared_ptr<Bullet>(BulletCreator::Create(type, loc)));
}

void BulletManager::Delete(int index)
{
	m_Bullets[index]->SetDeleteFlg(true);
}

void BulletManager::Refresh()
{
	for(int i = 0, size = m_Bullets.size(); i < size; i++)
	{
		if(m_Bullets[i]->GetDeleteFlg() == true)
		{
			m_Bullets.erase(m_Bullets.begin() + i);
			i = -1;
			size--;
		}
	}
}

void BulletManager::Action()
{
	for(int i = 0, size = m_Bullets.size(); i < size; i++)
	{
		m_Bullets[i]->Action();
	}
}

void BulletManager::Move()
{
	for(int i = 0, size = m_Bullets.size(); i < size; i++)
	{
		m_Bullets[i]->Move();
	}
}

void BulletManager::Draw()
{
	for(int i = 0, size = m_Bullets.size(); i < size; i++)
	{
		m_Bullets[i]->Draw();
	}
}