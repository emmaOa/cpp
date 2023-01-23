/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:39:43 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/23 19:07:31 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    hit_points = 100;
    eng_points = 100;
    att_damage = 30;
    std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap &obj)
{
    std::cout << "Copy constructor called\n";
    *this = obj;
}

FragTrap &FragTrap::operator=(const FragTrap &a)
{
    std::cout << "FragTrap Copy assignment operator called\n";
    name = a.name;
    hit_points = a.hit_points;
    eng_points = a.eng_points;
    att_damage = a.att_damage;
    return *this; 
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
    if (hit_points <= 0 || eng_points <= 0)
        return;
    this->eng_points--;
    std::cout << "FragTrap attack " << target << ".\n";
}

void highFivesGuys(void)
{
    std::cout << "Give me Five✋!!\n";
}
