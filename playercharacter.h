#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "pointwell.h"
#include "statblock.h"
#include "ability.h"

typedef std::uint16_t leveltype;
typedef std::uint64_t exptype;

class PlayerCharacterDelegate : public StatBlock
{
public:
	static const exptype NEXTLEVELAT = 100u;

	PlayerCharacterDelegate() : StatBlock(0u, 0u),
								CurrentLevel(1u),
								CurrentExp(0u),
								EXPToNextLevel(NEXTLEVELAT),
								HP(std::make_unique<PointWell>()) {}

	void gainExp(exptype gainedExp)
	{
		CurrentExp += gainedExp;
		while (check_if_leveled())
		{
		}
	}

	leveltype getLevel() { return CurrentLevel; }
	exptype getCurrentExp() { return CurrentExp; }
	exptype getExpToNextLevel() { return EXPToNextLevel; }

	virtual void LevelUp() = 0;
	virtual std::string getClassName() = 0;

	std::unique_ptr<PointWell> HP;
	std::unique_ptr<PointWell> MP;

	std::vector<Ability> Abilities;

protected:
	leveltype CurrentLevel;
	exptype CurrentExp;
	exptype EXPToNextLevel;

	bool check_if_leveled()
	{
		if (CurrentExp < EXPToNextLevel)
			return false;

		static const leveltype LEVELSCALER = 2u;
		CurrentLevel++;
		LevelUp();
		EXPToNextLevel *= LEVELSCALER;
		return true;
	}
};

class PlayerCharacter
{
private:
	PlayerCharacterDelegate *pcclass;

public:
	PlayerCharacter() = delete;
	PlayerCharacter(PlayerCharacterDelegate *pc) : pcclass(pc) {}

	~PlayerCharacter()
	{
		delete pcclass;
		pcclass = nullptr;
	}

	leveltype getLevel() { return pcclass->getLevel(); }
	exptype getCurrentExp() { return pcclass->getCurrentExp(); }
	exptype getExpToNextLevel() { return pcclass->getExpToNextLevel(); }
	stattype getStrength() { return pcclass->getStrength(); }
	stattype getIntellect() { return pcclass->getIntellect(); }
	stattype getAgility() { return pcclass->getAgility(); }
	stattype getArmor() { return pcclass->getArmor(); }
	stattype getElementResistance() { return pcclass->getElementResistance(); }
	welltype getCurrentHP() { return pcclass->HP->getCurrent(); }
	welltype getMaxHP() { return pcclass->HP->getMax(); }
	welltype getCurrentMP() { return (pcclass->MP) ? pcclass->MP->getCurrent() : 0; }
	welltype getMaxMP() { return (pcclass->MP) ? pcclass->MP->getMax() : 0; }
	std::string getClassName() { return pcclass->getClassName(); }

	std::vector<Ability> getAbilityList() { return pcclass->Abilities; }

	void gainEXP(exptype amt) { pcclass->gainExp(amt); }
	void takeDamage(welltype amt) { pcclass->HP->reduceCurrent(amt); }
	void heal(welltype amt) { pcclass->HP->increaseCurrent(amt); }
};

#define PCCONSTRUCT                  \
	HP->setMax(BASEHP);              \
	HP->increaseCurrent(BASEHP);     \
	if (MP)                          \
	{                                \
		MP->setMax(BASEMP);          \
		MP->increaseCurrent(BASEMP); \
	}                                \
	increaseStats(BASESTR, BASEINT, BASEAGI);

#define LEVELUP                                              \
	HP->setMax((welltype)(BASEHP / 2.f) + HP->getMax());     \
	HP->increaseCurrent((welltype)(BASEHP / 2.f));           \
	if (MP)                                                  \
	{                                                        \
		MP->setMax((welltype)(BASEMP / 2.f) + MP->getMax()); \
		MP->increaseCurrent((welltype)(BASEMP / 2.f));       \
	}                                                        \
	increaseStats((stattype)((BASESTR + 1u) / 2.f),          \
				  (stattype)((BASEINT + 1u) / 2.f),          \
				  (stattype)((BASEAGI + 1u) / 2.f));

class Cleric : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 14u;
	static const welltype BASEMP = 10u;
	static const stattype BASESTR = 3u;
	static const stattype BASEINT = 5u;
	static const stattype BASEAGI = 1u;

	Cleric() : PlayerCharacterDelegate()
	{
		MP = std::make_unique<PointWell>((welltype)BASEMP, (welltype)BASEMP); // always init before pcconstruct macro
		PCCONSTRUCT;
		Abilities.emplace_back("Heal", 2u, 1u, ABILITYTARGET::ALLY, 2u,
							   ABILITYSCALER::INT);
	}

	std::string getClassName() override { return std::string("Cleric"); }

private:
	void LevelUp() override
	{
		LEVELUP;
		if (CurrentLevel == 2)
		{
			Abilities.emplace_back("Smite", 2u, 1u, ABILITYTARGET::ENEMY, 2u,
								   ABILITYSCALER::INT);
		}
	}
};

class Rogue : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 12u;
	static const welltype BASEMP = 0u;
	static const stattype BASESTR = 3u;
	static const stattype BASEINT = 3u;
	static const stattype BASEAGI = 6u;

	std::string getClassName() override { return std::string("Rogue"); }

	Rogue() : PlayerCharacterDelegate() { PCCONSTRUCT; }

private:
	void LevelUp() override
	{
		LEVELUP;
		if (CurrentLevel == 2)
		{
			Abilities.emplace_back("PreciseAttack", 0u, 3u, ABILITYTARGET::ENEMY, 6u,
								   ABILITYSCALER::INT);
		}
	}
};

class Warrior : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 18u;
	static const welltype BASEMP = 0u;
	static const stattype BASESTR = 6u;
	static const stattype BASEINT = 2u;
	static const stattype BASEAGI = 2u;

	std::string getClassName() override { return std::string("Warrior"); }

	Warrior() : PlayerCharacterDelegate() { PCCONSTRUCT; }

private:
	void LevelUp() override
	{
		LEVELUP;
		if (CurrentLevel == 2)
		{
			Abilities.emplace_back("PowerAttack", 0u, 3u, ABILITYTARGET::ENEMY, 4u,
								   ABILITYSCALER::INT);
		}
	}
};

class Wizard : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 10u;
	static const welltype BASEMP = 14u;
	static const stattype BASESTR = 1u;
	static const stattype BASEINT = 8u;
	static const stattype BASEAGI = 2u;

	std::string getClassName() override { return std::string("Wizard"); }

	Wizard() : PlayerCharacterDelegate()
	{
		MP = std::make_unique<PointWell>((welltype)BASEMP, (welltype)BASEMP); // always init before pcconstruct macro
		PCCONSTRUCT;
		Abilities.emplace_back("Firebolt", 2u, 1u, ABILITYTARGET::ENEMY, 4u,
							   ABILITYSCALER::INT);
	}

private:
	void LevelUp() override
	{
		LEVELUP;
		if (CurrentLevel == 2)
		{
			Abilities.emplace_back("IceBolt", 3u, 1u, ABILITYTARGET::ENEMY, 6u,
								   ABILITYSCALER::INT);
			MP->setMax(1u + MP->getMax());
			MP->increaseCurrent(1u);
			increaseStats(0, 1);
		}
	}
};
