
/******************************** 
*Name - CHIRAG ALWANI
*DATE: 2018/7/21
*Student Id- 153444179 
*********************************/
#include <iostream>
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double interest_rate = 0.05;
	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* acc_type, double initialbal)
	{
		iAccount* account = nullptr;

	
		if (acc_type[0] == 'S')
		{
			account = new SavingsAccount(initialbal, interest_rate);
		}
		return account;
	}
}
