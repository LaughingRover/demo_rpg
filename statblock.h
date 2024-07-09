#pragma once

typedef std::uint16_t stattype;

class StatBlock
{
public:
	StatBlock() : strength(1u), intellect(1u) {}

	explicit StatBlock(stattype s, stattype i) : strength(s), intellect(i) {}

	stattype getStrength() const { return strength; }
	stattype getIntellect() const { return intellect; }

protected:
	void increaseStats(stattype s, stattype i) {
		strength += s;
		intellect += i;
	}

private:
	stattype strength;
	stattype intellect;
};
