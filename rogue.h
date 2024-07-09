#pragma once
#include "character.h"

class Rogue : public Character
{
public:
	Rogue() : Character(BASEHP, BASESTR, BASEINT) {}

private:
	void LevelUp() override
	{
		setMaxHP(getMaxHP() + HPGROWTH);
		increaseStats(STRGROWTH, INTGROWTH);
	}

	static const hptype BASEHP = 12u;
	static const stattype BASESTR = 3u;
	static const stattype BASEINT = 2u;

	static const hptype HPGROWTH = 6u;
	static const stattype STRGROWTH = 2u;
	static const stattype INTGROWTH = 1u;
};
