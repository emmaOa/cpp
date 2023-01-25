/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:09:21 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/25 16:57:53 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat ::Cat()
{
    this->type = "Cat";
    this->_cat_brain = new Brain();
    std::cout << "Cat constructor called\n";
}

Cat ::Cat(const Cat  &obj)
{
    std::cout << "Cat Copy constructor called\n";
    *this = obj;
}

Cat  &Cat::operator=(const Cat  &a)
{
    std::cout << "Cat Copy assignment operator called\n";
    type = a.type;
    return *this; 
}

Cat ::~Cat ()
{
    delete _cat_brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound(void) const
{
    std::cout << "The Cat says: mew mew \n";
}