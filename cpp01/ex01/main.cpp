/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:31:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/16 12:05:27 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int nb;
    int i = 0;
    std::string name;
    Zombie* zombies;

    std::cout << "entry number of zombies : ";
    std::cin >> nb;
    std::cout << "entry name : ";
    std::cin >> name;
    zombies = zombieHorde(nb, name);
    while (i < nb)
    {
        zombies[i].announce();
        i++;
    }
    delete [] zombies;
    system("leaks Zombies");
}