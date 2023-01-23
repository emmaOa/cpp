/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:29 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:33 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main( void )
{
    ClapTrap c1("c1");
    ClapTrap c2("c2");
    ClapTrap c3("c3");
    ScavTrap c4("c4");
    FragTrap c5("c5");
    
    c1.attack("c2");
    c4.attack("c2");
    c5.attack("c2");
    c2.takeDamage(5);
    c4.takeDamage(5);
    c5.takeDamage(5);
    c2.beRepaired(3);
    c4.beRepaired(1);
    c5.beRepaired(2);
    c3.attack("c1");
}