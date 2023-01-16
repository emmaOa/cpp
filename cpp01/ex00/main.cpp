/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:31:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/05 19:40:01 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;
    Zombie* n_zombie;

    std::cout << "entry name : ";
    std::cin >> name;
    randomChump(name);
    n_zombie = newZombie(name);
    n_zombie->announce();
    delete(n_zombie);
}