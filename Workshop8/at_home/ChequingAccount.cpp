// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double init_bal, double tra_fees, double month_fees):Account(init_bal)
	{
		if (tra_fees != 0 && month_fees != 0)
		{

			transaction_fees = tra_fees;
			monthend_fee = month_fees;

		}
		else
		{
			transaction_fees = 0.0;
			monthend_fee = 0.0;
		}

	}
	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double creamt)
	{
		if (Account::credit(creamt))
		{
			Account::debit(transaction_fees);
			return true;
		
		}
		else
		{
			return false;
		}
	}
	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double debamt)
	{
		if (Account::debit(debamt))
		{
			Account::debit(transaction_fees);
			return true;

		}
		else
		{
			return false;
		}
	}
	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd()
	{
		Account::debit(monthend_fee + transaction_fees);
	}
	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const
	{
		os << "Account type: Chequing" << std::endl;
		os << "Balance: $" << balance() << std::endl;
		os << "Per Transaction Fee: " << transaction_fees << std::endl;
		os << "Monthly Fee: " << monthend_fee << std::endl;
	}








}