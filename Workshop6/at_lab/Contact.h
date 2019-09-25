#ifndef NAMESPACE_CONTACT_H_
#define	NAMESPACE_CONTACT_H_

namespace sict
{
	class Contact
	{

		char person_name[20];
		long long int *contact_number;
		int total_num;

	public:
		Contact();
		Contact(const char*, long long int*, int);
		~Contact();

		bool isEmpty() const;
		void display() const;


	};
}
#endif 