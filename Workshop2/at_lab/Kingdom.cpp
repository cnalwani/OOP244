/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 24 May 2018
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
namespace sict{

    // TODO:definition for display(...) 
    void display(const Kingdom &kingdom)
	{
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}