/***********************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date :8/9/2018
***********************************/
#include <iostream>
#include "Perishable.h"

using namespace std;

namespace AMA
{

	Perishable::Perishable() : Product('P')
	{

	}
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		Product::store(file, false);
		file << "," << dateobj;
		if (newLine)
			file << std::endl;		
		return file;

	}
	std::fstream& Perishable::load(std::fstream& file)
	{

		Product::load(file);
		dateobj.read(file);
		file.ignore();
		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		Product::write(os, linear);
		if (isClear() && !isEmpty())
		{
			if (linear)
				dateobj.write(os);
			else
			{
				os << "\n Expiry date: ";
				dateobj.write(os);
			}
		}
		return os;
	}
	std::istream& Perishable::read(std::istream& is)
	{

		Product::read(is);//this should also check for errors and report back?
		if (!is.fail())//if is did not fail
		{
			Date temp;
			std::cout << " Expiry date (YYYY/MM/DD): ";//COMPLETE
			temp.read(is);//this should retrun is.fail if not in format and
						  //is.ignore();

			if (temp.errCode() != 0)
			{
				switch (temp.errCode()) {

				case (1):
					this->message("Invalid Data Entry");
					break;
				case (2):
					this->message("Invalid Year in Date Entry");
					break;
				case (3):
					this->message("Invalid Month in Date Entry");
					break;
				case (4):
					this->message("Invalid Day in Date Entry");
					break;
				}
				is.setstate(std::ios::failbit);
			}
			if (temp.errCode() == 0)
			{
				dateobj = temp;//TODO: Does this copy object or not?
			}
		}
		//	is.ignore();
		return is;
	}
	const Date & Perishable::expiry() const
	{
		return dateobj;
	}
}
