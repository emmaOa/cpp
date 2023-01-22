/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:49 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/22 00:28:34 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixed_nb = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nb)
{
    _fixed_nb = (nb << _fract_nb);
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nb)
{
    _fixed_nb = roundf((nb * (float)(1<<_fract_nb)));
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called\n";
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &a)
{
    std::cout << "Copy assignment operator called\n";
    _fixed_nb = a._fixed_nb;
    return *this; 
}

std::ostream &operator<<(std::ostream &ret, const Fixed &a)
{
    ret << a.toFloat();
    return ret;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
    return _fixed_nb;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";
    _fixed_nb = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_fixed_nb / (float)(1<<_fract_nb));
}

int Fixed::toInt( void ) const
{
    return (_fixed_nb >> _fract_nb);
}
