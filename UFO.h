#ifndef UFO_H_INCLUDED_
#define UFO_H_INCLUDED_

#include "Character.h"

class UFO : public Character
{
public:
	UFO(Location loc);
	~UFO(void);

	virtual void Kill();
	void Action();
	void Move();
};

#endif //UFO_H_INCLUDED_