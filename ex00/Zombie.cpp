/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:32:21 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/16 11:52:23 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{}

Zombie::~Zombie(void)
{
    std::cout << this->_name << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
