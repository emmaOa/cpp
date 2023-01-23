/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:39:36 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:59 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    hit_points = 100;
    eng_points = 50;
    att_damage = 20;
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    std::cout << "Copy constructor called\n";
    *this = obj;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &a)
{
    std::cout << "ScavTrap Copy assignment operator called\n";
    name = a.name;
    hit_points = a.hit_points;
    eng_points = a.eng_points;
    att_damage = a.att_damage;
    return *this; 
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_points <= 0 || eng_points <= 0)
        return;
    this->eng_points--;
    std::cout << "ScavTrap attack " << target << ".\n";
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}
