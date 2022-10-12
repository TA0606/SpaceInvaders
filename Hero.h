#ifndef HERO_H_INCLUDED_
#define HERO_H_INCLUDED_

#include "Character.h"

class Hero : public Character
{
public:
	Hero(Location loc);
	~Hero(void);

	void AddScore(int add){ m_Data.Score += add; }
	virtual void Kill();
	void Action();
	void Move();
};

#endif //HERO_H_INCLUDED_
