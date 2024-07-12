#pragma once

typedef std::uint16_t stattype;

class StatBlock
{
public:
	explicit StatBlock(stattype s = 1u, stattype i = 1u, stattype a = 1u,
					   stattype arm = 0u, stattype elemRes = 0u)
		: strength(s), intellect(i),
		  agility(a), armor(arm), elementResistance(elemRes) {}

	stattype getStrength() const { return strength; }
	stattype getIntellect() const { return intellect; }
	stattype getAgility() const { return agility; }
	stattype getArmor() const { return armor; }
	stattype getElementResistance() const { return elementResistance; }

protected:
	void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0,
					   stattype arm = 0, stattype elemRes = 0)
	{
		strength += s;
		intellect += i;
		agility += a;
		armor += arm;
		elementResistance += elemRes;
	}

private:
	stattype strength;
	stattype intellect;
	stattype agility;
	stattype armor;
	stattype elementResistance;
};
