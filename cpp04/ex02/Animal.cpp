/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:09:21 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/25 17:56:34 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal()
{
    std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy constructor called\n";
    *this = obj;
}

Animal &Animal::operator=(const Animal &a)
{
    std::cout << "Animal Copy assignment operator called\n";
    type = a.type;
    return *this; 
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

void Animal::makeSound(void) const
{
    std::cout << "all animal have a sound\n";
}