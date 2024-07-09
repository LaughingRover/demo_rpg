#pragma once
#include "Typedef.h"

class StatBlock {
public:
	StatBlock() : strength(1u), intellect(1u) {}

	explicit StatBlock(stattype s, stattype i) : strength(s), intellect(i) {}

	stattype getStrength() const { return strength; }
	stattype getIntellect() const { return intellect; }

private:
	stattype strength;
	stattype intellect;
};
