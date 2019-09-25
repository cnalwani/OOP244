#ifndef NAMESPACE_HERO_H_
#define	NAMESPACE_HERO_H_
//#include <iostream>

namespace sict
{
	class Hero
	{
		char hero_name[40];
		int hero_health;
		int hero_strength;

	public:

		Hero();
		Hero(const char*,int, int);
		void operator-=(int attack);
		bool isAlive() const;
		bool isEmpty() const;
		int attackStrength() const;
	//	void getName(Hero &hero);
		friend 	std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	std::ostream& operator<<(std::ostream& os, const Hero& hero);
	const Hero& operator*(const Hero& first, const Hero& second);

}
#endif