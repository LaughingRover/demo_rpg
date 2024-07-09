#pragma once
#include <cstdint>

typedef std::uint16_t hptype;

class HP {
public:
	bool setMaxHP(hptype new_max_hp) {
		if (new_max_hp < 1)
			return false;

		MaxHP = new_max_hp;

		if (CurrentHP > MaxHP)
			CurrentHP = MaxHP;

		return true;
	}

	hptype getCurrentHP() const {
		return CurrentHP;
	}

	hptype getMaxHP() const {
		return MaxHP;
	}

	void takeDamage(hptype damage) {
		if (damage > CurrentHP)
		{
			CurrentHP = 0;
			return;
		}

		CurrentHP -= damage;
	}

	void heal(hptype amount) {
		if (amount + CurrentHP > MaxHP)
		{
			CurrentHP = MaxHP;
			return;
		}

		CurrentHP += amount;
	}

	HP() : CurrentHP (1), MaxHP(1) {}

	HP(hptype cHP, hptype mHP) : CurrentHP(cHP), MaxHP(mHP) {
		if (CurrentHP > MaxHP)
			CurrentHP = MaxHP;
	}

private:
	hptype CurrentHP;
	hptype MaxHP;
};
