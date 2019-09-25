/********************************
*Name - CHIRAG ALWANI
*DATE: 2018/7/24
*Student Id- 153444179
*********************************/
#include <iostream>
#include "ChequingAccount.h"
#include "SavingsAccount.h" 

namespace sict {

	//double interest_rate = 00.5;
	double trasaction_fees = 0.50;
	double monthly_fees = 2.00;

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
		else if (acc_type[0] == 'C')
		{
			account = new ChequingAccount(initialbal, trasaction_fees, monthly_fees);

		}
		return account;
	}
}
