#pragma once
#include "character.h"

class Rogue : public Character
{
public:
	static const hptype HPGrowth = 13u;
	static const stattype BaseStr = 5u;
	static const stattype BaseInt = 2u;

	Rogue() : Character(HPGrowth, BaseStr, BaseInt) {}
};
