#ifndef GAMEOVER_H_INCLUDED_
#define GAMEOVER_H_INCLUDED_

#include "Sequence.h"
#include "Utils.h"

class GameOver : public Sequence
{
private:
	int m_Count;
public:
	GameOver(void);
	void Refresh();
};

#endif //GAMEOVER_H_INCLUDED_