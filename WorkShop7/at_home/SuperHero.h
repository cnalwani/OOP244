#ifndef NAMESPACE_SUPERHERO_H_
#define	NAMESPACE_SUPERHERO_H_

#include <iostream>
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero
	{ 
		private:
			int attak_bonus;
			int defe_strength;
		public:
			SuperHero();
			SuperHero(const char*, int, int, int, int);
			int attackStrength() const;
			int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_SUPERHERO_H
