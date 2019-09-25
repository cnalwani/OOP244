/********************************
*Name - CHIRAG ALWANI
*DATE: 2018/7/24
*Student Id- 153444179
*********************************/
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <iostream>
#include "Account.h"

namespace sict
{

	class SavingsAccount : public Account
	{

		double interest;
	public:
		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);
		// TODO: perform month end transactions
		void monthEnd();
		// TODO: display inserts the account information into an ostream			
		void display(std::ostream& os) const;
	};

}
#endif
