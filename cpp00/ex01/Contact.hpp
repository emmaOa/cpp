#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickename;
		std::string _darkest_secret;
		std::string  _phone_number;
	public:
		Contact(void);
		~Contact(void);
		std::string get_var(int i);
		int set_str(int i);
};
int	isnumber(std::string number);

#endif