#pragma once
#include "character.h"

class Cleric : public Character
{
public:
	Cleric() : Character(BASEHP, BASESTR, BASEINT) {}

private:
	void LevelUp() override
	{
		setMaxHP(getMaxHP() + HPGROWTH);
		increaseStats(STRGROWTH, INTGROWTH);
	}

	static const hptype BASEHP = 14u;
	static const stattype BASESTR = 2u;
	static const stattype BASEINT = 3u;

	static const hptype HPGROWTH = 7u;
	static const stattype STRGROWTH = 1u;
	static const stattype INTGROWTH = 2u;
};
