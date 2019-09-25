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



