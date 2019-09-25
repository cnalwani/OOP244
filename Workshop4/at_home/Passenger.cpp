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
		if (Name == '\0' || Dest == '\0')
		{
			pass_name[0] = '\0';
			destination[0] = '\0';
		}
		else
		{
			strncpy(pass_name, Name, 31);
			strncpy(destination, Dest, 31);
			yr_departure = 2017;
			mn_departure = 7;
			dy_departure = 1;

		}
	}
	Passenger::Passenger(const char* Name, const char* Dest, int year, int month, int day )
	{
		if (Name == '\0' || Dest == '\0' || Name[0] == '\0' || Dest[0] == '\0' || year < 2017 || year > 2020 || month < 1 || month > 12 || day < 1 || day > 31)
		{
			
				pass_name[0] = '\0';
				destination[0] = '\0';

				year = 0;
				month = 0;
				day = 0;
			
		}
		else
		{
			strncpy(pass_name, Name, 31);
			strncpy(destination, Dest, 31);

			yr_departure = year;
			mn_departure = month;
			dy_departure = day;
		}
	}
	
	const char* Passenger::name() const
	{
		return (pass_name);
	}
	bool Passenger::canTravelWith(const Passenger& p) const
	{
		bool result = true;
		if (strcmp(p.destination, destination)!=1 && p.yr_departure == yr_departure && p.mn_departure == mn_departure && p.dy_departure == dy_departure)
		{
			result = true;
		}
		else
		{
			result = false;
		}
		return result;
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
			if (mn_departure < 10)
			{
				cout << pass_name << " - " << destination << " on " << yr_departure << "/0" << mn_departure << "/" << dy_departure << endl;

			}
			else
			{
				cout << pass_name << " - " << destination << " on " << yr_departure << "/" << mn_departure << "/" << dy_departure << endl;
			}
		}
	}
}
