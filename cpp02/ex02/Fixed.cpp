/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:49 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/22 01:15:39 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixed_nb = 0;
}

Fixed::Fixed(const int nb)
{
    _fixed_nb = (nb << _fract_nb);
}

Fixed::Fixed(const float nb)
{
    _fixed_nb = roundf((nb * (float)(1<<_fract_nb)));
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &a)
{
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
}

int Fixed::getRawBits( void ) const
{
    return _fixed_nb;
}

void Fixed::setRawBits( int const raw )
{
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

bool Fixed::operator >(const Fixed &b) const
{
    if (this->toFloat() > b.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator <(const Fixed &b) const
{
    if (this->toFloat() < b.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator >=(const Fixed &b) const
{
    if (this->toFloat() >= b.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator <=(const Fixed &b) const
{
    if (this->toFloat() <= b.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator !=(const Fixed &b) const
{
    if (this->getRawBits() != b.getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator ==(const Fixed &b) const
{
    if (this->getRawBits() == b.getRawBits())
        return 1;
    return 0;
}

Fixed Fixed::operator+(const Fixed &b) const
{
    return this->toFloat() + b.toFloat();
}

Fixed Fixed::operator-(const Fixed &b) const
{
    return this->toFloat() - b.toFloat();
}

Fixed Fixed::operator*(const Fixed &b) const
{
    return this->toFloat() * b.toFloat();  
}

Fixed Fixed::operator/(const Fixed &b) const
{
    return this->toFloat() / b.toFloat();
}

Fixed& Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed& Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed a(*this);
    ++*this;
    return a;
}

Fixed Fixed::operator--(int)
{
    Fixed a(*this);
    --*this;
    return a;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.operator>(b))
        return b;
    return a;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.operator>(b))
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.operator>(b))
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.operator>(b))
        return b;
    return a;
}
