/********************************
*Name - CHIRAG ALWANI
*DATE: 2018/7/24
*Student Id- 153444179
*********************************/
#include <iostream>
#include "SavingsAccount.h"

using namespace std;
namespace sict
{
	SavingsAccount::SavingsAccount(double init_bal, double rate) : Account(init_bal)
	{
		if (rate > 0)
		{
			interest = rate;
		}
		else
		{
			interest = 0.0;
		}
	}
	void SavingsAccount::monthEnd()
	{
		double totalinterest = (balance() * interest);

		credit(totalinterest);

	}
	void SavingsAccount::display(std::ostream& os) const
	{
		os.setf(ios::fixed);
		os.precision(2);
		os << "Account type: Savings" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << interest * 100 << endl;
	}
}
