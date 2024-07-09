#include <iostream>
#include "character_types.h"

using namespace std;

int main()
{
	Warrior warrior1;
	Wizard wizard1;
	Cleric cleric1;
	Rogue rogue1;

	for (int i = 0; i < 2; i++)
	{
		cout << "Warrior Level " << warrior1.getLevel() << '\n'
			 << "  -EXP: " << warrior1.getCurrentExp() << "/" << warrior1.getExpToNextLevel() << '\n'
			 << "  -MaxHP: " << warrior1.getMaxHP() << '\n'
			 << "  -Strength: " << warrior1.getStrength() << '\n'
			 << "  -Intellect: " << warrior1.getIntellect() << '\n'
			 << endl;
		if (i < 1)
			warrior1.gainExp(100u);
	}

	return 0;
}
