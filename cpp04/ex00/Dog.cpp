/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:09:21 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/25 15:42:51 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog Copy constructor called\n";
    *this = obj;
}

Dog &Dog::operator=(const Dog &a)
{
    std::cout << "Dog Copy assignment operator called\n";
    type = a.type;
    return *this; 
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound(void)  const
{
    std::cout << "The dog says: how how \n";
}