#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

int	isnumber(std::string number)
{
	int i = number.length();
	if (number == "")
		return 1;
	while (--i >= 0)
	{
		if (std::isdigit(number[i]) == 0 && (number[i] != '+' && i == 0))
			return 1;
	}
	return 0;
}

std::string Contact::get_var(int i)
{
	if (i == 0)
		return this->_first_name;
	else if (i == 1)
		return this->_last_name;
	else if (i == 2)
		return this->_nickename;
	else if (i == 3)
		return this->_darkest_secret;
	else
		return this->_phone_number;
}

int Contact::set_str(int i)
{
	std::string print;

	switch (i)
	{
		case 0:
			{
				std::cout << "first name : ";
				if (!getline(std::cin, print))
				 	exit(0);
				if (print.empty())
					return 1;
				this->_first_name = print;
			}
			break;
		case 1:
			{
				std::cout << "last name : ";
				if (!getline(std::cin, print))
					exit(0);
				if (print == "")
					return 1;
				this->_last_name = print;
			}
			break;
		case 2:
			{
				std::cout << "nickename : ";
				if (!getline(std::cin, print))
					exit(0);
				if (print == "")
					return 1;
				this->_nickename = print;
			}
			break;
		case 3:
			{
				std::cout << "darkest secret : ";;
				if (!getline(std::cin, print))
					exit(0);
				if (print == "")
					return 1;
				this->_darkest_secret = print;
			}
			break;
		case 4:
		{
			std::cout << "phone number : ";
			if (!getline(std::cin, print))
				exit(0);
			if (isnumber(print) == 0)
				this->_phone_number = print;
			else
			{
				std::cout << "phone number invalid" << std::endl;
				return 1;
			}
		}
		break;
		default:
			break;
	}
	return 0;
}