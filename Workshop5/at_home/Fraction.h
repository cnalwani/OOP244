#pragma once
// TODO: header file guard

#ifndef NAMESPACE_FRACTION_H_
#define NAMESPACE_FRACTION_H_

// TODO: create namespace

namespace sict
{
	// TODO: define the Fraction class
	class Fraction
	{

		// TODO: declare instance variables 

		int numerator;
		int denominator;

		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;


	public:

		// TODO: declare public member functions
		Fraction();
		Fraction(int num, int deno);
		bool isEmpty() const;
		void display() const;


		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;

		Fraction operator+=(const Fraction& rhs);

	};

}
#endif 
