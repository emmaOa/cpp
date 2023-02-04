/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:05 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/25 16:53:14 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain Copy constructor called\n";
    *this = obj;
}

Brain &Brain::operator=(const Brain &a)
{
    std::cout << "Brain Copy assignment operator called\n";
    for (int i = 0; i < 100; i++)
        _ideas[0] = a._ideas[0];
    return *this; 
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}