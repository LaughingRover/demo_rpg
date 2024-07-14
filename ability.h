#pragma once
#include <string>

enum ABILITYTARGET
{
	SELF = 0,
	ENEMY = 1,
	ALLY = 2
};

enum ABILITYSCALER
{
	NONE,
	STR,
	AGI,
	INT
};

struct Ability
{
	Ability(std::string name, uint32_t cost, uint32_t cd, ABILITYTARGET t,
			uint32_t e, ABILITYSCALER s)
		: Name(name), Cost(cost), Cooldown(cd), Target(t), HP_Effect(e),
		Scaler(s) {}

	std::string Name = "unnamed";
	uint32_t Cost = 0;	   // assume mp if there is a cost
	uint32_t Cooldown = 1; // number of rounds you have to wait before using it again
	ABILITYTARGET Target = ABILITYTARGET::SELF;
	uint32_t HP_Effect = 1;
	ABILITYSCALER Scaler = ABILITYSCALER::NONE;
};