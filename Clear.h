#ifndef CLEAR_H_INCLUDED_
#define CLEAR_H_INCLUDED_

#include "Sequence.h"
#include "Utils.h"

class Clear : public Sequence
{
private:
	int m_Count;
public:
	Clear(int stage);
	void Refresh();
};

#endif //CLEAR_H_INCLUDED_