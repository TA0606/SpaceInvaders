#ifndef STAGETITLE_H_INCLUDED_
#define STAGETITLE_H_INCLUDED_

#include "Sequence.h"
#include "Utils.h"

class StageTitle : public Sequence
{
private:
	int m_StageNum;
	int m_Count;
public:
	StageTitle(int stage);
	void Refresh();
};

#endif //STAGETITLE_H_INCLUDED_
