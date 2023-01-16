/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:59:50 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/09 15:16:55 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & weapon) : _name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{}

void HumanA::attack()
{
     std::cout << this->_name << " " << this->_weapon.getType() << std::endl;
}
