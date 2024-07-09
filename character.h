#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelsystem.h"

class Character : public HP, public StatBlock
{
public:
	Character(hptype hpGrowth, stattype baseStr, stattype baseInt)
		: HP(hpGrowth, hpGrowth), StatBlock(baseStr, baseInt) {}

protected:
	LevelSystem levelUp;
};
