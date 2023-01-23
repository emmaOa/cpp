/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:29 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/23 19:04:09 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main( void )
{
    ClapTrap c1("c1");
    ClapTrap c2("c2");
    ClapTrap c3("c3");
    ScavTrap c4("c4");
    
    c1.attack("c2");
    c4.attack("c2");
    c2.takeDamage(5);
    c4.takeDamage(5);
    c2.beRepaired(3);
    c4.beRepaired(1);
    c3.attack("c1");
}