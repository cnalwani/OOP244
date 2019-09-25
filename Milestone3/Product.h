/***********************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date : 8/3/2018
***********************************/
#ifndef NAMESPACE_PRODUCT_H_
#define NAMESPACE_PRODUCT_H_

//#include <iostream>
#include "ErrorState.h"

namespace AMA
{

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Product
	{

	private:

		char pro_type;
		char pro_sku[max_sku_length + 1];
		char pro_unit[max_unit_length + 1];
		char* pro_name;
		int quan_onhand;
		int quan_needed;
		double price_befortax;
		bool tax_status;
		ErrorState product_error;

	protected:

		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:

		Product(char product_type = 'N');

		Product(const char *sku, const char *name, const char *unit, int onhand_qua = 0, bool status = 0, double price_tax = 0, int needed_qua = 0);

		Product(const Product& os);

		Product& operator=(const Product& os);         // copy assignment operator

		~Product();

		std::fstream& store(std::fstream& file, bool newLine = true) const;

		std::fstream& load(std::fstream& file);

		std::ostream& write(std::ostream& os, bool linear) const;

		std::istream& read(std::istream& is);

		bool operator==(const char*) const;

		double total_cost() const;

		void quantity(int);

		bool isEmpty() const;

		int qtyNeeded() const;

		int quantity() const;

		bool operator>(const char*) const;

		bool operator>(const Product&) const;

		int operator+=(int);
	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}


#endif // !NAMESPACE_PRODUCT_H_
