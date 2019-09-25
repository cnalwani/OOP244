/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 24 May 2018
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

	// TODO: declare the function display(...),
	void display(const Kingdom &);


}
#endif