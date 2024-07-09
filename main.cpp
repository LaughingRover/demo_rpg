#include <iostream>
#include "character_types.h"

using namespace std;

int main()
{
	Warrior warrior1;
	Wizard wizard1;
	Cleric cleric1;
	Rogue rogue1;

	cout << "Warrior\n"
		<< "-MaxHP " << warrior1.getMaxHP() << '\n'
		<< "-Strength " << warrior1.getStrength() << '\n'
		<< "-Intellect " << warrior1.getIntellect() << endl;

	return 0;
}
