#pragma once
#include "character.h"

class Wizard : public Character
{
public:
	static const hptype HPGrowth = 9u;
	static const stattype BaseStr = 1u;
	static const stattype BaseInt = 4u;

	Wizard() : Character(HPGrowth, BaseStr, BaseInt) {}
};
