#include <iostream>
#include "CRA_Account.h"
#include <cstring>

using namespace std;
namespace sict
{
	
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{


		if (sin < min_sin || sin > max_sin)
		//if (sin > min_sin || sin < max_sin)
		{

			strncpy(this->familyName, "\0", max_name_length + 1); //using 'this' to access object
			strncpy(this->givenName, "\0", max_name_length + 1);
			this->sin = 0;

		}
		else
		{
		
			strncpy(this->familyName, familyName, max_name_length + 1); //using 'this' to access object
			strncpy(this->givenName, givenName, max_name_length + 1);
			this->sin = sin;
		}

	}
	bool CRA_Account::isEmpty() const 
	{
		if (sin == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void CRA_Account::display() const
	{

		cout << "Family Name: " << familyName << endl;
		cout << "Given Name : " << givenName << endl;
		cout << "CRA Account: " << sin << endl;

	}
}
