#include <iostream>
#include "Hero.h"
#include "SuperHero.h"
#define max_rounds 100

using namespace std;
namespace sict {

	SuperHero::SuperHero()
	{
		Hero();
		attak_bonus = 0;
		defe_strength = 0;
	}
	SuperHero::SuperHero(const char* name, int health, int strength, int attack_bonus, int defence) : Hero(name, health, strength)
	{
		attak_bonus = attack_bonus;
		defe_strength = defence;
	}
	int SuperHero::attackStrength() const
	{
		if (this->attak_bonus == 0 && this->defe_strength == 0 && Hero::attackStrength() == 0)
		{
			return 0;
		}
		else
		{
			return (Hero::attackStrength() + attak_bonus);
		}
	}

	int SuperHero::defend() const
	{

		if (defe_strength == 0)
		{
			return 0;
		}
		else
		{
			return defe_strength;
		}
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero y = first;
		SuperHero z = second;
		cout << "Super Fight! " << first << " vs " << second << " : ";
		int rounds = 0;
		const SuperHero *winner = nullptr;
		while (y.isAlive() && z.isAlive() && rounds < max_rounds)
		{
			rounds++;
			y -= (z.attackStrength() - y.defend());
			z -= (y.attackStrength() - z.defend());
		}
		if (y.isAlive() == true)
		{
			winner = &first;
		}
		else
		{
			winner = &second;
		}
		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}


}
