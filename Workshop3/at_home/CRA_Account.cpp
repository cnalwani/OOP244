/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
//Student Number : 153444179
///////////////////////////////////////////////////////////
// Name			             Date
// CHIRAG ALWANI       6 june 2018
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
namespace sict {


	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{


		if ((sin >= min_sin && sin <= max_sin) && (familyName[0] != '\0' && givenName[0] != '\0'))
		{
			int q = (sin % 10); //to seperate all values of integer 

			int w = ((sin / 10) % 10) * 2;
			if (w > 9)
			{
				w = (w / 10) + (w % 10); // to add digits seperately example: in case of 11, 1+1=2
			}

			int e = (sin / 100) % 10;

			int r = ((sin / 1000) % 10) * 2;
			if (r > 9)
			{
				r = (r / 10) + (r % 10);
			}

			int t = (sin / 10000) % 10;

			int y = ((sin / 100000) % 10) * 2;
			if (y > 9)
			{
				y = (y / 10) + (y % 10);
			}

			int u = (sin / 1000000) % 10;

			int i = ((sin / 10000000) % 10) * 2;
			if (i > 9)
			{
				i = (i / 10) + (i % 10);
			}

			int o = (sin / 100000000) % 10;

			int odd = e + t + u + o;
			int even = w + r + y + i;
			int sum = odd + even; // sum of all digits
			int multiple = ((sum / 10) + 1) * 10; // to find nearest multiple of 10 near to that number example 50 in case of 43
			int diff = multiple - sum;

			if (diff == q)
			{
				strncpy(this->familyName, familyName, max_name_length + 1);
				strncpy(this->givenName, givenName, max_name_length + 1);
				this->sin = sin;
				yrs = 0;
			}

			else // if sin is between minimum and maximum but still invalid
			{

				strncpy(this->familyName, "\0", max_name_length + 1); //using 'this' to access object
				strncpy(this->givenName, "\0", max_name_length + 1);
				this->sin = 0;
			}

		}
	}

	bool CRA_Account::isEmpty() const
	{
		if (this->sin >= min_sin && this->sin <= max_sin)
		{
			return false;
		}

		else

			return true;
	}

	void CRA_Account::display() const
	{
		cout << "Family Name: " << familyName << endl;
		cout << "Given Name : " << givenName << endl;
		cout << "CRA Account: " << sin << endl;

		cout.setf(ios::fixed);
		cout.precision(2);

		for (int i = 0; i < yrs; i++) {
			if (bal[i] > 2) {
				cout << "Year (" << ret_yr[i] << ")" << " balance owing: " << bal[i] << endl;
			}
			else if (bal[i] < -2) {
				cout << "Year (" << ret_yr[i] << ")" << " refund due: " << -1 * bal[i] << endl;
			}
			else {
				cout << "Year (" << ret_yr[i] << ")" << " No balance owing or refund due!" << endl;
			}
		}

		cout.precision(6);
		cout.unsetf(ios::fixed);
	}

	void CRA_Account::set(int year, double balance)
	{
		if (!isEmpty())
		{
			for (int i = 0; i < max_yrs; i++)
			{
				if (ret_yr[i] == 0)
				{
					ret_yr[i] = year;
					bal[i] = balance;
					yrs += 1;
					i = max_yrs;
				}
			}
		}
	}
}
