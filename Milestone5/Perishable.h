/***********************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date :8/9/2018
***********************************/

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include <iostream>
#include "Product.h"
#include "Date.h"

namespace AMA
{

	class Perishable : public Product 
	{
	
		Date dateobj;
	public:

		Perishable();

		std::fstream& store(std::fstream& file, bool newLine=true) const;

		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;	
	};

	iProduct* CreatePerishable();
}
#endif // NAMESPACE_PERISHABLE_H_