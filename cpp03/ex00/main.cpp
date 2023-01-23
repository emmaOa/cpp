/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:29 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/23 18:56:29 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap c1("c1");
    ClapTrap c2("c2");
    ClapTrap c3("c3");

    c1.attack("c2");
    c2.takeDamage(5);
    c2.beRepaired(3);
    c3.attack("c1");
    
}