// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict
{


	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		numerator = 0;
		denominator = 0;

	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int den)
	{
		if (num < 0 || den < 0)
		{
			numerator = 0;
			denominator = 0;
		}
		else
		{
			numerator = num;
			denominator = den;
			reduce();
		}

	}
	// TODO: implement the max query
	int Fraction::max() const
	{
		if (numerator > denominator)
		{
			return numerator;
		}
		else
		{
			return denominator;
		}

	}
	// TODO: implement the min query
	int Fraction::min() const
	{
		if (numerator < denominator)
		{
			return numerator;
		}
		else
		{
			return denominator;
		}

	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const
	{
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x)
		{
			// from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;

				g_c_d = x;
			}
		}
		return g_c_d;

	}
	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int gc = gcd();
		numerator = numerator / gc;
		denominator = denominator / gc;

	}
	// TODO: implement the display query
	void Fraction::display() const
	{
		if (numerator > 0 && denominator > 1)
		{
			cout << numerator << "/" << denominator;
		}
		else if (numerator > 0 && denominator == 1)
		{
			cout << numerator;
		}
		else
		{
			cout << "no fraction stored";
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		if (numerator == 0 && denominator == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// TODO: implement the + operator

	Fraction Fraction::operator+(const Fraction& rhs) const
	{

		if (rhs.isEmpty() == false && this->isEmpty() == false)
		{
			int ans1 = ((this->numerator * rhs.denominator) + (this->denominator * rhs.numerator));

			int ans2 = this->denominator * rhs.denominator;

			return Fraction(ans1, ans2);
		}
		else
		{
			return Fraction();

		}
	}
	Fraction Fraction::operator*(const Fraction& rhs) const
	{

		if (rhs.isEmpty() == false && this->isEmpty() == false)
		{
			int ans3 = this->numerator*rhs.numerator; //((this->numerator * rhs.denominator) * (this->denominator * rhs.numerator));

			int ans4 = this->denominator * rhs.denominator;

			return Fraction(ans3, ans4);
		}
		else
		{
			return Fraction();

		}
	}


	
	bool Fraction::operator==(const Fraction& rhs) const
	{
		if (rhs.isEmpty() == false && this->isEmpty() == false && this->numerator == rhs.numerator && this->denominator == rhs.denominator)
		{
			
			
				return true;
			

		}
		else
		{
			return false;
		}
	}

	bool Fraction::operator!=(const Fraction& rhs) const
	{
		bool result = false;
		if (rhs.isEmpty() == false && this->isEmpty() == false)
		{
			return result;
		}
		else
		{
			return result;
		}

	}

	Fraction Fraction::operator+=(const Fraction& rhs) 
	{
		Fraction i;
		i = *this + rhs;
		*this = i;
        return *this;
	}
}
