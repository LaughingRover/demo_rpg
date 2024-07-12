#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include "pointwell.h"
#include "statblock.h"

typedef std::uint16_t leveltype;
typedef std::uint64_t exptype;

class PlayerCharacterDelegate : public StatBlock
{
public:
	static const exptype NEXTLEVELAT = 100u;

	PlayerCharacterDelegate(welltype baseHP, stattype baseSTR, stattype baseINT) : StatBlock(0u, 0u),
																				   CurrentLevel(1u),
																				   CurrentExp(0u),
																				   EXPToNextLevel(NEXTLEVELAT),
																				   BASEHP(baseHP),
																				   BASESTR(baseSTR),
																				   BASEINT(baseINT),
																				   HP(std::make_unique<PointWell>())
	{
		HP->setMax(BASEHP);
		HP->increaseCurrent(BASEHP);
		increaseStats(BASESTR, BASEINT);
	}

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

	virtual std::string getClassName() = 0;

	std::unique_ptr<PointWell> HP;

protected:
	leveltype CurrentLevel;
	exptype CurrentExp;
	exptype EXPToNextLevel;

	welltype BASEHP;
	stattype BASESTR;
	stattype BASEINT;

	bool check_if_leveled()
	{
		if (CurrentExp < EXPToNextLevel)
			return false;

		static const leveltype LEVELSCALER = 2u;
		CurrentLevel++;
		levelUp();
		EXPToNextLevel *= LEVELSCALER;
		return true;
	}

	void levelUp()
	{
		HP->setMax((welltype)(BASEHP / 2.f) + HP->getMax());
		HP->increaseCurrent((welltype)(BASEHP / 2.f));
		increaseStats((stattype)((BASESTR + 1u) / 2.f),
					  (stattype)((BASEINT + 1u) / 2.f));
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
	welltype getCurrentHP() { return pcclass->HP->getCurrent(); }
	welltype getMaxHP() { return pcclass->HP->getMax(); }
	std::string getClassName() { return pcclass->getClassName(); }

	void gainEXP(exptype amt) { pcclass->gainExp(amt); }
	void takeDamage(welltype amt) { pcclass->HP->reduceCurrent(amt); }
	void heal(welltype amt) { pcclass->HP->increaseCurrent(amt); }
};

class Cleric : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 14u;
	static const stattype BASESTR = 2u;
	static const stattype BASEINT = 3u;

	Cleric() : PlayerCharacterDelegate(BASEHP, BASESTR, BASEINT) {}

	std::string getClassName() override { return std::string("cleric"); }
};

class Rogue : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 12u;
	static const stattype BASESTR = 3u;
	static const stattype BASEINT = 2u;

	Rogue() : PlayerCharacterDelegate(BASEHP, BASESTR, BASEINT) {}

	std::string getClassName() override { return std::string("Rogue"); }
};

class Warrior : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 18u;
	static const stattype BASESTR = 4u;
	static const stattype BASEINT = 1u;

	Warrior() : PlayerCharacterDelegate(BASEHP, BASESTR, BASEINT) {}

	std::string getClassName() override { return std::string("Warrior"); }
};

class Wizard : public PlayerCharacterDelegate
{
public:
	static const welltype BASEHP = 10u;
	static const stattype BASESTR = 1u;
	static const stattype BASEINT = 4u;

	Wizard() : PlayerCharacterDelegate(BASEHP, BASESTR, BASEINT) {}

	std::string getClassName() override { return std::string("Wizard"); }
};
