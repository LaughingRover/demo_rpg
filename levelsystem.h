#pragma once
#include <cstdint>

typedef std::uint16_t leveltype;
typedef std::uint64_t exptype;

class LevelSystem
{
public:
	static const exptype NEXTLEVELAT = 100u;

	LevelSystem() : CurrentLevel(1u),
					CurrentExp(0u),
					EXPToNextLevel(NEXTLEVELAT) {}

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
