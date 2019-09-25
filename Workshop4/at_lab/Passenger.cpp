// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;
namespace sict
{
	// TODO: implement the default constructor here
	Passenger::Passenger()
	{
		pass_name[0] = '\0';
		destination[0] = '\0';

	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* Name, const char* Dest)
	{
		if (Name == '\0' || Dest == '\0' || Name[0] == '\0' || Dest[0] == '\0')
		{
			pass_name[0] = '\0';
			destination[0] = '\0';

		}
		else
		{
			strncpy(pass_name,Name,32);
			strncpy(destination,Dest,32);
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const
	{
		if (pass_name == '\0' || destination == '\0' || pass_name[0] == '\0' || destination[0] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// TODO: implement display query here
	void Passenger::display() const
	{
		if (isEmpty() == true)
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << pass_name << " - " << destination << endl;
		}
	}
}
