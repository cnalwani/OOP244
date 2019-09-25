#pragma once
#ifndef NAMESPACE_CRA_ACCOUNT_H_
#define NAMESPACE_CRA_ACCOUNT_H_

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account
	{
	private:
		char familyName[max_name_length];
		char givenName[max_name_length];
		int sin;
		int ret_yr[max_yrs] = { 0 };
		double bal[max_yrs];
		int yrs; // no. of years with record

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);

	};
}
#endif