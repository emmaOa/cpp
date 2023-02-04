/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:09:21 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/04 23:41:40 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->_Dog_brain = new Brain();
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog Copy constructor called\n";
    if (this != &obj) {
        *_Dog_brain = *(obj._Dog_brain);
    }
    *this = obj;
}

Dog &Dog::operator=(const Dog &a)
{
    std::cout << "Dog Copy assignment operator called\n";
    type = a.type;
    _Dog_brain = a._Dog_brain;
    return *this; 
}

Dog::~Dog()
{
    delete _Dog_brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound(void)  const
{
    std::cout << "The dog says: how how \n";
}