/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:32:21 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/05 20:21:46 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie(void)
{
    std::cout << this->_name << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
