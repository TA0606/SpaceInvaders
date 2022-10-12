#ifndef ENDING_H_INCLUDED_
#define ENDING_H_INCLUDED_

#include "Sequence.h"
#include "Utils.h"

class Ending : public Sequence
{
private:
	int m_Count;
public:
	Ending(void);
	void Refresh();
};

#endif //ENDING_H_INCLUDED_