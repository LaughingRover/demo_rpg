#pragma once
#include "character.h"

class Warrior : public Character
{
public:
	static const hptype HPGrowth = 19u;
	static const stattype BaseStr = 4u;
	static const stattype BaseInt = 1u;

	Warrior() : Character(HPGrowth, BaseStr, BaseInt) {}
};
