#include "TroopMemberCreator.h"

TroopMember* TroopMemberCreator::Create(int type, Location loc)
{
	switch(type)
	{
	case TroopMemberCreator::TYPE_A:
		return new TroopMember_A(loc);
		break;
	case TroopMemberCreator::TYPE_B:
		return new TroopMember_B(loc);
		break;
	case TroopMemberCreator::TYPE_C:
		return new TroopMember_C(loc);
		break;
	default:
		return NULL;
		break;
	}
}