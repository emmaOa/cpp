/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:49 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/21 00:12:23 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixed_nb = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed &obj)
{
    std::cout << "Copy constructor called\n";
    *this = obj;
}

Fixed &Fixed::operator=(Fixed &a)
{
    std::cout << "Copy assignment operator called\n";
    _fixed_nb = a.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return _fixed_nb;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";
    _fixed_nb = raw;
}
