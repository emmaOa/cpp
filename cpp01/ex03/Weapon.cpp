/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:40:29 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/09 11:36:42 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{}

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

std::string const & Weapon::getType( void )
{
	return this->_type;
}
void  Weapon::setType( std::string tp )
{
  this->_type = tp;
}
