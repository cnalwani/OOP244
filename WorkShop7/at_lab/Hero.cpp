	/********************************************
*NAME: CHIRAG ALWANI
*ID# : 153444179
*DATE : 2018 / 7 / 13
*********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#define max_rounds 100

using namespace std;
namespace sict
{

	Hero::Hero()
	{
		hero_name[0] = '\0';
		hero_health = 0;
		hero_strength = 0;
	}
	Hero::Hero(const char* name, int health, int strength)
	{
		strncpy(hero_name, name, 39);
		hero_health = health;
		hero_strength = strength;
	}
	void Hero::operator-=(int attack)
	{
		if (attack > 0)
		{
			this->hero_health = this->hero_health - attack;
			if (this->hero_health < 0)
				this->hero_health = 0;
		}
	}
	bool Hero::isAlive() const
	{

		if (hero_health > 0)
		{

			return true;
		}
		else
		{
			return false;
		}

	}
	int Hero::attackStrength() const
	{
		if (this->hero_strength == 0)
			return 0;
		else
			return this->hero_strength;
		//return hero_strength;
	}
	
	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.hero_name == '\0' || hero.hero_name == nullptr)
		{
			os << "No Hero";
		}
		else
		{
			os << hero.hero_name;
		}
		return os;
	}
	const Hero& operator*(const Hero &first, const Hero &second)
	{
		Hero y = first;
		Hero z = second;
		cout << "Ancient Battle! " << first << " vs " << second << " :";
		int rounds = 0;
		const Hero *winner = nullptr;


		while (y.isAlive() == true && z.isAlive() == true && rounds < max_rounds)
		{

			y-=(z.attackStrength());
			z-=(y.attackStrength());
			rounds++;

		}
		if (y.isAlive() == true)
		{
			winner = &first;
		}
		else
		{
			winner = &second;
		}

		cout << " Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}
	
}
