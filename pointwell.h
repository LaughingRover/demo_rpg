#pragma once
#include <cstdint>

typedef std::uint16_t welltype;

class PointWell
{
public:
	PointWell() : Current(1), Max(1) {}

	PointWell(welltype current, welltype max) : Current(current), Max(max)
	{
		if (Current > Max)
			Current = Max;
	}

	bool setMax(welltype new_max)
	{
		if (new_max < 1)
			return false;

		Max = new_max;

		if (Current > Max)
			Current = Max;

		return true;
	}

	welltype getCurrent() const
	{
		return Current;
	}

	welltype getMax() const
	{
		return Max;
	}

	void reduceCurrent(welltype damage)
	{
		if (damage > Current)
		{
			Current = 0;
			return;
		}

		Current -= damage;
	}

	void increaseCurrent(welltype amount)
	{
		if (amount + Current > Max)
		{
			Current = Max;
			return;
		}

		Current += amount;
	}

private:
	welltype Current;
	welltype Max;
};
