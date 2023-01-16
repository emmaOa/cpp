/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:44:20 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/02 21:30:48 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phonebook(-1);
	std::string opr;
	int old_ind;
	phonebook.set_nb(0);

	while (1)
	{
		old_ind = phonebook.get_ind();
		std::cout << "choice your operation" << std::endl;
		if (!getline(std::cin, opr) || opr == "EXIT")
			exit(0);
		if (opr == "ADD")
		{
			if (phonebook.get_ind() == 7)
			{
				phonebook.set_ind(-2);
				phonebook.set_nb(1);
			}
			else
				phonebook.set_ind(-3);
			if (phonebook.add() == 1)
				phonebook.set_ind(old_ind);
		}
		else if (opr == "SEARCH")
		{
			if (phonebook.get_ind() == -1)
				std::cout << "empty phon contact" << std::endl;
			else
				phonebook.p_search();
		}
		else
			std::cout << "invalide input" << std::endl;
	}
}
