#ifndef TROOPMEMBERCREATOR_H_INCLUDED_
#define TROOPMEMBERCREATOR_H_INCLUDED_

#include "TroopMember_A.h"
#include "TroopMember_B.h"
#include "TroopMember_C.h"

class TroopMemberCreator
{
public:
	enum TypeTag{ TYPE_A, TYPE_B, TYPE_C };
	static TroopMember* Create(int type, Location loc);
};

#endif //TROOPMEMBERCREATOR_H_INCLUDED_