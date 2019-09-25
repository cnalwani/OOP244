#pragma once
#ifndef NAMESPACE_CRA_ACCOUNT_H_
#define NAMESPACE_CRA_ACCOUNT_H_

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account
	{
	private:
		char familyName[max_name_length];
		char givenName[max_name_length];
		int sin;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
#endif