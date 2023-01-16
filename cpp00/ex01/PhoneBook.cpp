/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:44:29 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/02 21:31:06 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(int in) : _ind(in)
{}

PhoneBook::~PhoneBook(void)
{}

int PhoneBook::get_ind( void )
{
	return this->_ind;
}

void PhoneBook::set_ind(int i)
{
	if (i == -3)
		this->_ind++;
	else if (i == -2)
		this->_ind = 0;
	else
		this->_ind = i;
}

void PhoneBook::set_nb(int i)
{
	this->nb_con = i;
}

int	PhoneBook::add(void)
{
	int n_con = 0;
	while (n_con < 5)
	{
		if (this->_contact[this->_ind].set_str(n_con) == 1)
			return 1;
		n_con++;
	}
	return 0;
}

std::string string_f(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

int	PhoneBook::p_search(void)
{
	int i = 0;
	int nb = 0;
	nb = this->_ind;
	if (this->nb_con == 1)
		nb = 7;
	std::string inp;
	std::cout << std::setw(10) << string_f("INDEX") \
	<< "|" << std::setw(10) << string_f("FIRST NAME") \
	<< "|" << std::setw(10) << string_f("LAST NAME") << "|" << std::setw(10) << string_f("nickname") << std::endl;
	while (i <= nb)
	{
		std::cout << std::setw(10) << i << "|" << std::setw(10) \
		<< string_f(this->_contact[i].get_var(0)) \
		<< "|" << std::setw(10) << string_f(this->_contact[i].get_var(1)) \
		<< "|" << std::setw(10) << string_f(this->_contact[i].get_var(2)) << std::endl;
		i++;
	}
	std::cout << "entry index : ";
	if (!getline(std::cin, inp))
		exit(0);
	if (isnumber(inp) == 0)
		i = std::stoi(inp);
	else
	{
		std::cout << "invalid index" << std::endl;
		return 1;
	}
	if (i > nb || i < 0)
	{
		std::cout << "invalid index" << std::endl;
		return 1;
	}
	std::cout << this->_contact[i].get_var(0) \
	<< "\n" << this->_contact[i].get_var(1) \
	<< "\n" << this->_contact[i].get_var(2) \
	<< "\n" << this->_contact[i].get_var(3) \
	<< "\n" << this->_contact[i].get_var(4) \
	<< std::endl;
	return 0;
}
