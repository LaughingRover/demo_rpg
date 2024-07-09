#pragma once
#include "character.h"

class Warrior : public Character
{
public:
	Warrior() : Character(BASEHP, BASESTR, BASEINT) {}

private:
	void LevelUp() override
	{
		setMaxHP(getMaxHP() + HPGROWTH);
		increaseStats(STRGROWTH, INTGROWTH);
	}

	static const hptype BASEHP = 19u;
	static const stattype BASESTR = 4u;
	static const stattype BASEINT = 1u;

	static const hptype HPGROWTH = 9u;
	static const stattype STRGROWTH = 2u;
	static const stattype INTGROWTH = 1u;
};
