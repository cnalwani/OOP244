/***********************************
* Name: CHIRAG ALWANI
* Student ID: 153444179
* Date :8/9/2018
***********************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include"Product.h"

using namespace std;

namespace AMA
{

	void Product::name(const char* pr_nm) //recieves and stores name of product
	{
		if (pr_nm != nullptr)
		{
			if (pro_name != nullptr) //delete any existing data in name pointer
			{
				delete[] pro_name;
				pro_name = nullptr;
			}

			pro_name = new char[(strlen(pr_nm)) + 1];
			strcpy(pro_name, pr_nm);
			pro_name[strlen(pr_nm)] = '\0';
		}
		else
			pro_name = nullptr;
	}


	const char* Product::name() const //returns address to name of product
	{
		return pro_name;

	}
	//returns products sku
	const char* Product::sku() const //returns address to sku of product
	{
		return pro_sku;
	}
	//returns product unit
	const char* Product::unit() const //returns address to unit of product
	{
		return pro_unit;
	}
	//returns product tax status
	bool Product::taxed() const //returns taxable status
	{
		return tax_status;
	}

	//return product price 
	double Product::price() const //returns price of single item
	{
		return price_befortax;
	}
	//return final cost of a single item adding tax.
	double Product::cost() const
	{
		if (tax_status)
			return (price()*(tax_rate + 1));

		return price();
	}
	//stores an error message
	void Product::message(const char* err_msg) //recieves and stores error message
	{
		product_error.message(err_msg);
	}

	//checks error message status
	bool Product::isClear() const //checks if ErrorState is clear
	{
		return product_error.isClear();
	}

	Product::Product(const char type) //default constructor
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
	Product::Product(const char *sku, const char *_name, const char *unit, const int onhand_qua, const bool status, double price_tax, const int needed_qua) : Product()//constructor with 7 arguments
	{
		if (sku != nullptr && _name != nullptr && unit != nullptr)
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
		else
		{
			pro_sku[0] = '\0';
			pro_unit[0] = '\0';
			pro_name = nullptr;
			quan_onhand = 0;
			quan_needed = 0;
			price_befortax = 0.0;
			tax_status = false;
		}
	}


	Product::Product(const Product& temp)//copy constructor
	{
		*this = temp; //calls assignment operator 
	}
	Product& Product::operator=(const Product& temp)//Copy Assignment Operator 
	{
		if (this != &temp)
		{
			pro_type = temp.pro_type;
			strncpy(pro_sku, temp.pro_sku, strlen(temp.pro_sku));
			pro_sku[strlen(temp.pro_sku)] = '\0';
			strncpy(pro_unit, temp.pro_unit, strlen(temp.pro_unit));
			pro_unit[strlen(temp.pro_unit)] = '\0';
			name(temp.pro_name);
			quan_onhand = temp.quan_onhand;
			quan_needed = temp.quan_needed;
			price_befortax = temp.price_befortax;
			tax_status = temp.tax_status;
			message(temp.product_error.message());
		}
		return *this;
	}
	Product::~Product()
	{
		if (pro_name != nullptr)
		{
			pro_name = nullptr;
			delete[] pro_name;
		}
	}

	//puts values of current object to file object
	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		if (file.is_open())
		{
			file << pro_type << "," << pro_sku << "," << pro_name << ",";
			file << pro_unit << "," << tax_status << "," << price_befortax << ",";
			file << quan_onhand << "," << quan_needed;

			if (newLine)
				file << endl;
		}

		return file;
	}
	//extracts data from incoming file
	std::fstream& Product::load(std::fstream& file)
	{
		Product temp;
		char name_temp[max_name_length + 1];
		file.get(temp.pro_sku, max_sku_length, ',');
		file.ignore();
		file.get(name_temp, max_name_length, ',');
		temp.name(name_temp);
		file.ignore();
		file.get(temp.pro_unit, max_unit_length, ',');
		file.ignore();
		file >> temp.tax_status;
		file.ignore();
		file >> temp.price_befortax;
		file.ignore();
		file >> temp.quan_onhand;
		file.ignore();
		file >> temp.quan_needed;
		file.ignore();
		*this = temp;
		return file;
	}

	//writes to an ostream object i.e reads from an object
	std::ostream& Product::write(std::ostream& os, bool linear) const
	{
		if (isClear())
		{
			if (linear)
			{
				os.setf(ios::left);
				os.width(max_sku_length);
				os << setfill(' ') << pro_sku << "|";

				os.width(20);
				os << setfill(' ') << pro_name << "|";
				os.unsetf(ios::left);

				os.setf(ios::fixed);
				os.width(7);
				os.precision(2);
				os << setfill(' ') << cost() << "|";

				os.width(4);
				os << setfill(' ') << quan_onhand << "|";

				os.setf(ios::left);
				os.width(10);
				os << setfill(' ') << unit() << "|";

				os.unsetf(ios::left);
				os.width(4);
				os << setfill(' ') << quan_needed << "|";
				os.setf(ios::fixed);
			}
			else
			{
				os << " Sku: " << sku() << endl;
				os << " Name (no spaces): " << name() << endl;
				os << " Price: " << price() << endl;
				os << " Price after tax: ";
				if (taxed())
					os << cost() << endl;
				else
					os << "N/A" << endl;
				os << " Quantity on Hand: " << quan_onhand;
				os << " " << unit() << endl;
				os << " Quantity needed: " << quan_needed;
			}
		}
		else
		{
			os << product_error.message();

		}
		return os;
	}

	//writes to istream obj i.e writes to a product object
	std::istream& Product::read(std::istream& is)
	{

		char sku[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qty_need;
		double price_before;
		char tax_stat;
		bool tax_status = false;
		bool okay = false;
		Product temp;


		cout << " Sku: "; is.getline(sku, max_sku_length);
		cout << " Name (no spaces): "; is.getline(name, max_name_length);
		cout << " Unit: "; is.getline(unit, max_unit_length);
		cout << " Taxed? (y/n): "; is >> tax_stat;

		if ((tax_stat == 'Y' || tax_stat == 'y') || tax_stat == 'n' || tax_stat == 'N')
		{
			if (tax_stat == 'Y' || tax_stat == 'y') {
				tax_status = true;
			}
			else if (tax_stat == 'n' || tax_stat == 'N'){
				tax_status = false;
			}
			okay = true;
		}
		else
		{
			product_error.message("Only (Y)es or (N)o are acceptable");
			is.setstate(ios::failbit);
		}

		if (okay)
		{
			cout << " Price: ";
			is >> price_before;
			if (is.fail())
			{
				product_error.message("Invalid Price Entry");
				okay = false;
			}
		}

		if (okay)
		{
			cout << " Quantity on hand: ";
			is >> quantity;
			if (is.fail())
			{
				product_error.message("Invalid Quantity Entry");
				okay = false;
			}
		}

		if (okay)
		{
			cout << " Quantity needed: ";
			is >> qty_need;
			if (is.fail())
			{
				product_error.message("Invalid Quantity Needed Entry");
				okay = false;
			}
		}


		if (!is.fail())
		{
			char type = pro_type;
			temp = Product(sku, name, unit, quantity, tax_status, price_before, qty_need);
			*this = temp;
			pro_type = type;
			is.ignore();
		}
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

	//change quantity avail to this
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
		int result = strncmp(pro_sku, ref, max_sku_length);
		if (result > 0)
			return true;
		return false;
	}

	bool Product::operator>(const iProduct& ref) const
	{
		int str1 = strlen(name());
		int str2 = strlen(ref.name());
		
		if (str1 > str2)
			return true;
		else
			return false;
	}
	//adds that much amount to quantity
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
	std::ostream &operator<<(std::ostream &os, const iProduct& ref)
	{
		ref.write(os, true);
		return os;
	}


	std::istream &operator>>(std::istream &is, iProduct& product)
	{
		product.read(is);
		return is;
	}

	//adds product cost to double total
	double operator+=(double &total, const iProduct& product)
	{
		total += product.total_cost();
		return total;
	}
}
