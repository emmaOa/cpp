/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:31:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/09 14:59:32 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
   
    // Weapon club = Weapon("crude spiked club");

    // HumanB jim("Jim");
    // jim.setWeapon(club);
    // jim.attack();
    // club.setType("some other type of club");
    // jim.attack();
    
    return 0;
}