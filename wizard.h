#pragma once
#include "character.h"

class Wizard : public Character
{
public:
	Wizard() : Character(BASEHP, BASESTR, BASEINT) {}

private:
	void LevelUp() override
	{
		setMaxHP(getMaxHP() + HPGROWTH);
		increaseStats(STRGROWTH, INTGROWTH);
	}

	static const hptype BASEHP = 10u;
	static const stattype BASESTR = 1u;
	static const stattype BASEINT = 4u;

	static const hptype HPGROWTH = 5u;
	static const stattype STRGROWTH = 1u;
	static const stattype INTGROWTH = 2u;
};
