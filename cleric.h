#pragma once
#include "character.h"

class Cleric : public Character
{
public:
	static const hptype HPGrowth = 14u;
	static const stattype BaseStr = 2u;
	static const stattype BaseInt = 2u;

	Cleric() : Character(HPGrowth, BaseStr, BaseInt) {}
};
