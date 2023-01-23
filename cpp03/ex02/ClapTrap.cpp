/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:49 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/23 18:57:17 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hit_points = 10;
    eng_points = 10;
    att_damage = 0;
    std::cout << "constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Copy constructor called\n";
    *this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a)
{
    std::cout << "Copy assignment operator called\n";
    name = a.name;
    hit_points = a.hit_points;
    eng_points = a.eng_points;
    att_damage = a.att_damage;
    return *this; 
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_points <= 0 || eng_points <= 0)
        return;

    this->eng_points--;

    std::cout << "ClapTrapk " << this->name << " attacks " << \
    target << ", causing " << this->att_damage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points <= 0 || eng_points <= 0)
        return;
    
    this->hit_points -= amount;

    std::cout << "ClapTrapk " << this->name << " takeDamage and lose " << \
    amount << " hit points.\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points <= 0 || eng_points <= 0)
        return;
    
    this->hit_points += amount;
    this->eng_points--;

    std::cout << "ClapTrapk " << this->name << " repairs itself " << \
    amount << " hit points back.\n";
}

