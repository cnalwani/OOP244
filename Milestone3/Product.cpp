/***********************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date :8/3/2018
***********************************/
#include <iostream>
#include "Product.h"
#include "MyProduct.h"
#include <cstring>
#include "ErrorState.h"

namespace AMA
{

	Product::Product(const char type)
	{
		pro_type = type;
		pro_sku[0] = '\0';
		pro_unit[0] = '\0';
		pro_name = nullptr;
		quan_onhand = 0;
		quan_needed = 0;
		price_befortax = 0.0;
		tax_status = false;
	}
	Product::Product(const char *sku, const char *_name, const char *unit, int onhand_qua, bool status, double price_tax, int needed_qua)
	{

		name(_name);
		strncpy(pro_sku, sku, max_sku_length);
		pro_sku[max_sku_length] = '\0';
		strncpy(pro_unit, unit, max_unit_length);
		pro_unit[max_unit_length] = '\0';

		quan_needed = needed_qua;
		quan_onhand = onhand_qua;
		price_befortax = price_tax;
		tax_status = status;
	}
	Product::~Product()
	{
		delete[] pro_name;
	}
	Product::Product(const Product& os)
	{
		int len = strlen(os.pro_name);

		strncpy(pro_sku, os.pro_sku, max_sku_length);
		pro_sku[max_sku_length] = '\0';

		strncpy(pro_unit, os.pro_unit, max_unit_length);
		pro_unit[max_unit_length] = '\0';

		pro_type = os.pro_type;
		quan_onhand = os.quan_onhand;
		quan_needed = os.quan_needed;
		price_befortax = os.price_befortax;
		tax_status = os.tax_status;

		if (os.pro_name != nullptr)
		{
			pro_name = nullptr;
			pro_name = new char[len];

			for (int i = 0; i < len; ++i)
			{
				pro_name[i] = os.pro_name[i];
			}
			pro_name[len] = '\0';
		}
		else
		{
			pro_name = nullptr;
		}
	}
	

	//sets the name of the product
	void Product::name(const char *nameAddress)
	{
		if (nameAddress != nullptr)
		{
			int length = strlen(nameAddress);

			pro_name = new char[length];
			for (int i = 0; i < length; ++i)
			{
				pro_name[i] = nameAddress[i];
			}

			pro_name[length] = '\0';
		}
	}
	//returns p_name adr
	const char *Product::name() const
	{
		if (pro_name == nullptr)
		{
			return nullptr;
		}
		else
		{
			return pro_name;
		}
	}
	//returns products sku
	const char *Product::sku() const
	{
		return pro_sku;
	}
	//returns product unit
	const char *Product::unit() const
	{
		return pro_unit;
	}
	//returns product tax status
	bool Product::taxed() const
	{
		return tax_status;
	}
	//return product price (befor taxes)
	double Product::price() const
	{
		return price_befortax;
	}
	//return final cost of a single item adding tax.
	double Product::cost() const
	{
		if (taxed())
		return (price()*(tax_rate + 1));
		return price();
	}
	void Product::message(const char *addressError)
	{
		product_error.message(addressError);
	}
	bool Product::isClear() const
	{
		return product_error.isClear();
	}
	//copy assignment operator
	Product &Product::operator=(const Product& os)
	{
		if (this != &os)
		{
			pro_type = os.pro_type;

			strncpy(pro_sku, os.sku(), max_sku_length);
			strncpy(pro_unit, os.unit(), max_unit_length);
			
			quan_onhand = os.quan_onhand;
			quan_needed = os.quan_needed;
			price_befortax = os.price_befortax;
			tax_status = os.tax_status;

			delete[] pro_name;

			if (os.pro_name != nullptr)
			{
				int len = strlen(os.pro_name);

				pro_name = new char[len];
				for (int i = 0; i < len; ++i)
				{
					pro_name[i] = os.pro_name[i];
				}
				pro_name[len] = '\0';
			}
			else
			{
				pro_name = nullptr;
			}
		}
		return *this;
	}
	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		file << pro_type << ',' << pro_sku << ',' << pro_unit << ',' << pro_name << ',' << quan_onhand << "," << tax_status << "," << price_befortax << "," << quan_needed;
		
		if (newLine)
		{
			file << std::endl;
		}	
		return file;
	}
	std::fstream& Product::load(std::fstream& file)
	{
		Product pt;
		pt.pro_name = new char[max_name_length + 1];

		if (file.is_open())
		{
			file >> pro_type >> pt.pro_sku >> pt.pro_unit >> pt.pro_name >> pt.quan_onhand >> pt.tax_status >> pt.price_befortax >> pt.quan_needed;
			*this = pt;
		}
		delete[] pt.pro_name;
		pt.pro_name = nullptr;
		return file;
	}
	std::ostream& Product::write(std::ostream &os, bool linear) const
	{
		if (linear)
		{

			os.setf(std::ios::left);
			os.width(max_sku_length);
			os << pro_sku << '|';
			os.width(20);
			os << pro_name << '|';
			os.width(7);
			os.unsetf(std::ios::left);
			os.setf(std::ios::fixed);
			os.precision(2);
			os << this->cost() << '|';
			os.width(4);
			os << this->quan_onhand << '|';
			os.width(10);
			os.setf(std::ios::left);
			os << pro_unit << '|';
			os.width(4);
			os.unsetf(std::ios::left);
			os << this->quan_needed << '|';

		}
		if (!linear)
		{
			os << "Sku: " << this->pro_sku << std::endl;
			os << "Name: " << this->pro_name << std::endl;
			os << "Price: " << this->cost() << std::endl;//Check this
			os << "Qunatity on hand: " << this->quan_onhand << std::endl;
			os << "Quantity needed: " << this->quan_needed << std::endl;
		}
		return os;
	}
	std::istream& Product::read(std::istream& is)
	{
		char sku[max_sku_length + 1];
		char *name = new char[max_name_length + 1];
		char unit[max_unit_length + 1];
		int onHand;
		int needed;
		double beforeTax;
		char tax;
		bool taxable;
		ErrorState error;

		std::cout << " Sku: ";
		is >> sku;

		std::cout << " Name (no spaces): ";
		is >> name;

		std::cout << " Unit: ";
		is >> unit;

		std::cout << " Taxed? (y/n): ";
		is >> tax;

		if (tax == 'Y' || tax == 'y')
		{
			taxable = true;
		}
		else if (tax == 'N' || tax == 'n')
		{
			taxable = false;
		}
		else
		{
			is.setstate(std::ios::failbit);
			error.message("Only(Y)es or (N)o are acceptable");
		}

		if (!is.fail())
		{
			std::cout << " Price: ";
			is >> beforeTax;
			if (is.fail())
				error.message("Invalid Price Entry");
		}

		if (!is.fail())
		{
			std::cout << " Quantity on hand: ";
			is >> onHand;
			if (is.fail())
				error.message("Invalid Quantity Entry");
		}
		if (!is.fail())
		{
			std::cout << " Quantity needed: ";
			is >> needed;
			if (is.fail())
			{
				error.message("Invalid Quantity Needed Entry");
			}
		}

		if (!is.fail())
		{
			Product pt = Product(sku, name, unit, onHand, taxable, beforeTax, needed);
			*this = pt;
		}

		delete[] name;
		name = nullptr;
		return is;
	}	

	//COMPARISON OPERATOR
	bool Product::operator==(const char *address) const
	{

		if (strncmp(pro_sku, address, max_sku_length) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//return total cost of all units including taxes
	double Product::total_cost() const
	{
		double taxed = price_befortax * tax_rate;
		double withTax = price_befortax + taxed;

		return quan_onhand * withTax;
	}
	void Product::quantity(int units)
	{
		quan_onhand = units;
	}
	bool Product::isEmpty() const
	{
		return (pro_name == nullptr) ? true : false;
	}
	int Product::qtyNeeded() const
	{
		return quan_needed;
	}
	int Product::quantity() const
	{
		return quan_onhand;
	}
	bool Product::operator>(const char *ref) const
	{
		int result = strncmp(pro_sku, ref, max_sku_length);//  0 if equal, < 0 if ref is bigger
		if (result > 0)
			return true;
		return false;
	}
	bool Product::operator>(const Product& ref) const
	{
		int str1 = strlen(pro_name);
		int str2 = strlen(ref.pro_name);
		int size = 0;
		if (str1 > str2)
			size = str1;
		else
			size = str2;
		return strncmp(pro_name, ref.pro_name, size);
	}
	int Product::operator+=(int un)
	{
		int temp;
		if (un > 0)
		{
			temp = quan_onhand += un;
		}
		else
		{
			temp = quan_onhand;
		}
		return temp;
		
	}
	//inserts Product to ostream
	std::ostream &operator<<(std::ostream &os, const Product& ref)
	{
		ref.write(os, true);//or false?
		return os;
	}

	std::istream &operator>>(std::istream &is, Product& product)
	{
		product.read(is);
		return is;
	}
	//adds product cost to double total
	double operator+=(double &total, const Product& product)
	{
		total += product.total_cost();
		return total;
	}
}