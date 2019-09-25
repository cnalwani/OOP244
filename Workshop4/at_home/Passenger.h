// TODO: add file header comments here
#pragma once
// TODO: add header file guard here
#ifndef NAMESPACE_PASSENGER_H_
#define NAMESPACE_PASSENGER_H_

// TODO: declare your namespace here
namespace sict
{

	class Passenger
	{
		char pass_name[32];
		char destination[32];

		int yr_departure;
		int mn_departure;
		int dy_departure;


	public:

		Passenger();
		Passenger(const char* Name, const char* Dest);
		Passenger(const char* Name, const char* Dest,int year, int month, int day);
		bool isEmpty() const;
		void display() const;

		bool canTravelWith(const Passenger&) const;
		const char* name() const;

	};

}

// TODO: define the Passenger class here

#endif 
