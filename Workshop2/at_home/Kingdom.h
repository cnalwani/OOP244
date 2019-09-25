
/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 2.0
// Date 29 May 2018
// Name CHIRAG ALWANI
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#pragma once

#ifndef NAMESPACE_KINGDOM_H_
#define NAMESPACE_KINGDOM_H_

// TODO: sict namespace

namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};

	void display(const Kingdom &);

	void display(const Kingdom *, int);


}
#endif
