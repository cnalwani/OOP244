/************************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date : 8/9/2018
***********************************/
#include <iostream>
#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

	}
	void Date::errCode(int errorCode)
	{
		error = errorCode;
	}
	Date::Date()
	{
		year = 0;
		month = 0;
		day = 0;
		comparator = 0;
		error = NO_ERROR;

	}
	Date::Date(int yy, int mm, int dd)
	{
		if (yy > MAX_YEAR || yy < MIN_YEAR)
		{
			error = YEAR_ERROR;
		}
		else if (mm > MAX_MON || mm < MIN_MON)
		{
			error = MON_ERROR;
		}
		else if (dd > MAX_DAY || dd < MIN_DAY)
		{
			error = DAY_ERROR;
		}
		else
		{
			day = dd;
			year = yy;
			month = mm;
			error = NO_ERROR;
			comparator = year * 372 + month * 13 + day;
		}
		if (error != NO_ERROR)
		{
			year = 0;
			day = 0;
			month = 0;
			comparator = 0;
		}
	}
	bool Date::operator==(const Date& rhs) const
	{
		if (year == rhs.year && month == rhs.month && day == rhs.day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::operator!=(const Date& rhs) const
	{
		if (year == rhs.year && month == rhs.month && day == rhs.day)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool Date::operator<(const Date& rhs) const
	{
		if (comparator < rhs.comparator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::operator>(const Date& rhs) const
	{
		if (year < rhs.year && month < rhs.month && day < rhs.month)
		{
			return false;
		}
		else
		{
			return true;
		}

	}
	bool Date::operator<=(const Date& rhs) const
	{
		if (year <= rhs.year && month <= rhs.month && day <= rhs.day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Date::operator>=(const Date& rhs) const
	{
		if (year >= rhs.year && month >= rhs.month && day >= rhs.day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Date::errCode() const
	{
		return error;
	}
	bool Date::bad() const
	{
		if (error == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	std::istream& Date::read(std::istream& istr)
	{
		int _year, _month, _day;
		istr >> _year;
		istr.ignore();
		istr >> _month;
		istr.ignore();
		istr >> _day;

		if (istr.fail() == true)
		{
			errCode(CIN_FAILED);
		}
		if (_year >= MIN_YEAR && _year <= MAX_YEAR)
		{
			year = _year;
		}
		else
		{
			errCode(YEAR_ERROR);
		}
		if (_month >= MIN_MON && _month <= MAX_MON)
		{
			month = _month;
		}
		else
		{
			errCode(MON_ERROR);
		}
		int days_ = mdays(month, year);
		if (_day <= days_)
		{
			day = _day;
			errCode(NO_ERROR);
		}
		else
		{
			errCode(DAY_ERROR);
		}
		if (error != NO_ERROR)
		{
			int temp = this->error;
			*this = Date();
			this->errCode(temp);
		}

		*this = Date(_year, _month, _day);
		return istr;
	}
	std::ostream& Date::write(std::ostream& ostr)const
	{

		ostr.width(1);
		ostr.fill('0');
		ostr << year << '/';
		ostr.width(2);
		ostr.fill('0');
		ostr << month << '/';
		ostr.width('0');
		ostr.width(2);
		ostr << day;

		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Date& d)
	{
		d.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Date& d)
	{
		d.read(istr);
		return istr;
	}
}