/************************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date : 8/9/2018
************************************/
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA 
{

#include <iostream>

#define MIN_YEAR 2000
#define MAX_YEAR 2030
#define MIN_MON 1
#define MAX_MON 12
#define MAX_DAY 31
#define MIN_DAY 1
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

	const int min_year = 2000;
	const int max_year = 2030;

	class Date 
	{


			private:

				int year;
				int month;
				int day;
				int error;
				int comparator;

				int mdays(int, int)const;
				void errCode(int errorCode);
			public:

				Date();
				Date(int, int, int);

				bool operator==(const Date& rhs) const;
				bool operator!=(const Date& rhs) const;
				bool operator<(const Date& rhs) const;
				bool operator>(const Date& rhs) const;
				bool operator<=(const Date& rhs) const;
				bool operator>=(const Date& rhs) const;

				int errCode() const;
				bool bad() const;
				std::istream& read(std::istream& istr);
				std::ostream& write(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream & ostr, const Date& d);
	std::istream& operator>>(std::istream & istr, Date& d);
}
#endif
