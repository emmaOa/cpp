/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:05:27 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/09 14:12:21 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{}

HumanB::~HumanB()
{}

void HumanB::attack()
{
    std::cout << this->_name << " " << this->_weapon->getType() << std::endl;
}

void  HumanB::setWeapon(Weapon & weapon)
{
  this->_weapon = &weapon;
}
