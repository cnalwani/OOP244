#include <iostream>
#include "Contact.h"
#include <cstring>

using namespace std;
namespace sict
{

	Contact::Contact()
	{
		person_name[0] = '\0';
		contact_number = nullptr;
		total_num = 0;

	}
	Contact::Contact(const Contact& src)
	{
		strncpy(person_name, src.person_name, 19);
		person_name[19] = '\0';
		total_num = src.total_num;

		if (src.contact_number != nullptr)
		{
			contact_number = new long long[total_num];

			for (int i = 0; i < total_num; i++)
			{
				contact_number[i] = src.contact_number[i];
			}
		}
		else
		{
			contact_number = nullptr;
		}
	}
	Contact::Contact(const char *name, long long int *number, int total)
	{
		if (name == nullptr || name[0] == '\0')
		{
			person_name[0] = '\0';
			contact_number = nullptr;
			total_num = 0;
		}

		else
		{
            strncpy(person_name, name, 19);
			person_name[19] = '\0';

			if (total > 0 && number == nullptr)
			{
				contact_number = nullptr;
				total_num = 0;
			}
			else
			{
				contact_number = nullptr;
				contact_number = new long long[total];
				total_num = 0;

				for (int i = 0; i < total; i++)
				{
					if (number[i] > 9999999999 && number[i] < 1000000000000 && (number[i] / 1000000) % 10 != 0 && (number[i] / 1000000000) % 10 != 0 && (number[i] / 10000000000) % 10 != 0)
					{
						contact_number[total_num] = number[i];
						total_num++;
					}
				}
			}
		}
	}
	
	
	Contact &Contact::operator=(const Contact &source)
	{

		if (this != &source)
		{

			strncpy(person_name, source.person_name, 19);
			person_name[19] = '\0';
			total_num = source.total_num;



			delete[] contact_number;

			if (source.contact_number != nullptr)
			{
				contact_number = new long long[total_num];

				for (int i = 0; i < total_num; i++)
				{

					contact_number[i] = source.contact_number[i];
				}
			}
			else
			{
				contact_number = nullptr;
			}	
		}
		return *this;
	}
	Contact Contact::operator+=(const long long number)
	{

		if (number > 9999999999 && number < 1000000000000 && (number / 1000000) % 10 != 0 && (number / 1000000000) % 10 != 0 && (number / 10000000000) % 10 != 0)
		{

			long long *temp = nullptr;
			temp = new long long[total_num + 1];


			for (int i = 0; i < total_num; i++)
			{

				temp[i] = contact_number[i];
			}
			temp[total_num] = number;
			total_num++;
			delete[] contact_number;
			contact_number = temp;


		}

		return *this;

	}
	Contact::~Contact()
	{
		delete[] contact_number;

	}
	bool Contact::isEmpty() const
	{
		if (person_name[0] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Contact::display() const
	{
		if (isEmpty() == true)
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << person_name << endl;

			for (int i = 0; i < total_num; i++)
			{

				int last_digit = (contact_number[i] % 10000);
				int mid_digit = (contact_number[i] % 10000000) / 10000;
				int country_code = contact_number[i] / 10000000000;
				int area_code = (contact_number[i] % 10000000000) / 10000000;


				cout << "(+" << country_code << ")";
				cout << " " << area_code << " ";
				cout << mid_digit << "-";
				cout << last_digit << endl;

			}
		}
	}
}



