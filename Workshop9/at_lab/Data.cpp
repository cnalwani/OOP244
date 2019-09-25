/**************************
*NAME: CHIRAG ALWANI
*ID#:  153444179
*DATE: 2018/7/28
***************************/
#include <iostream>
#include <cstring>
#include "Data.h"

using namespace std;

namespace sict 
{
	// A custom function for reading ints on min
	
	
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//


	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime, const double* violentCrimeRate, const int* grandTheftAuto, const int n) 
	{


		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int populationDiff = population[n - 1] - population[0];

		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << static_cast<double>(populationDiff) / 1000000 << " million" << endl;
	
		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		if (violentCrimeRate[0] > violentCrimeRate[n - 1])
		{
			cout << "Violent Crime trend is down" << endl;
		}
		else
		{
			cout << "Violent Crime trend is down" << endl;
		}
		
		// Q3 print the GTA number accurate to 0 decimal places
		double average;
		long long totalGTA = 0;

		for (int i = 0; i < n; i++)
		{
			totalGTA += grandTheftAuto[i];
		}
			
		average = totalGTA / n;

		cout << "There are ";
		cout.precision(2);
		cout << average / 1000000;
		cout << " million Grand Theft Auto incidents on average a year" << endl;
		
		// Q4. Print the min and max violentCrime rates

		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
	}
}