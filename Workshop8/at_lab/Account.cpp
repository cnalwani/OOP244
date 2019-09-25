/********************************
*Name - CHIRAG ALWANI
*DATE: 2018/7/21
*Student Id- 153444179
*********************************/
#include <iostream>
#include "Account.h"


namespace sict
{
	Account::Account(double initial_bal)
	{
		if (initial_bal <= 0)
		{
			this->curr_bala = 0.0;
		}
		else
		{
			this->curr_bala = initial_bal;
		}
	}
	bool Account::credit(double credit_amt)
	{
		if (credit_amt <=  0)
		{
		//	this->curr_bala = 0.0;
			
			return false;
		}
		else
		{
			this->curr_bala = curr_bala +  credit_amt;
		
			return true;
		}
	}
	bool Account::debit(double debit_amt)
	{
		if (debit_amt <= 0)
		{
		//	this->curr_bala = 0.0;
			
			return false;
		}
		else
		{
			this->curr_bala = curr_bala - debit_amt;
			
			return true;
		}
	}
	double Account::balance() const
	{
		return curr_bala;
	}
}