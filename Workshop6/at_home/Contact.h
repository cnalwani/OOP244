#ifndef NAMESPACE_CONTACT_H_
#define	NAMESPACE_CONTACT_H_

namespace sict
{
	class Contact
	{

		char person_name[20];
		long long *contact_number;
		int total_num;

	public:

		Contact();
		Contact(const char*, long long int*, int);
		Contact(const Contact&);
		~Contact();
		Contact& operator=(const Contact&);
		Contact operator+=(const long long);
		bool isEmpty() const;
		void display() const;


	};
}
#endif 