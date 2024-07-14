#include <iostream>
#include "playercharacter.h"

int main()
{
	PlayerCharacter p1(new Warrior());

	for (int i = 0; i < 2; i++)
	{
		std::cout
			<< p1.getClassName()
			<< " Level " << p1.getLevel() << '\n'
			<< " -EXP: " << p1.getCurrentExp() << "/" << p1.getExpToNextLevel() << '\n'
			<< " -HP: " << p1.getCurrentHP() << '/' << p1.getMaxHP() << '\n'
			<< " -MP: " << p1.getCurrentMP() << '/' << p1.getMaxMP() << '\n'
			<< " -Strength: " << p1.getStrength() << '\n'
			<< " -Intellect: " << p1.getIntellect() << '\n'
			<< " -Agility: " << p1.getAgility() << '\n'
			<< " -Armor: " << p1.getArmor() << '\n'
			<< " -Element Resistance: " << p1.getElementResistance() << '\n';

		auto allAbilities = p1.getAbilityList();

		std::cout << "-Abilities:\n";
		for (auto &Ability : allAbilities)
		{
			std::cout << " -" << Ability.Name << '\n';
		}
		std::cout << std::endl;

		if (i < 1)
			p1.gainEXP(100u);
	}

	return 0;
}
