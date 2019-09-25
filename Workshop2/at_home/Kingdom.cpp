/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 29 May 2018
// Name CHIRAG ALWANI
// Description
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers

#include <iostream>
#include "Kingdom.h"

// TODO: the sict namespace
using namespace std;
namespace sict {

	// TODO:definition for display(...) 
	void display(const Kingdom &kingdom)
	{
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}

	void display(const Kingdom *kingdom, int size)
	{
		int population = 0; // to display total population of all kingdoms

		for (int i = 0; i < size; i++)
		{
			population += kingdom[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". ";
			display(kingdom[i]);

		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << population << endl;
		cout << "------------------------------" << endl;

	}
}
