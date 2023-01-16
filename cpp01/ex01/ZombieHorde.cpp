/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:45:34 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/16 12:05:57 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    Zombie*	n_zombie = new Zombie[N];
    while (i < N)
    {
        n_zombie[i].set_name(name);
        i++;
    }
    return(n_zombie);
}