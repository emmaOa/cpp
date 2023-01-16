#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	private:
		Contact _contact[8];
		int	_ind;
		int	nb_con;

	public:
		PhoneBook(int in);
		~PhoneBook(void);
		int add(void);
		void set_nb(int i);
		void set_ind(int i);
		int p_search(void);
		int get_ind(void);
};
#endif
