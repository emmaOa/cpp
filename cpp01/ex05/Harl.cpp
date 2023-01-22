/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:08:29 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/16 15:44:23 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void (Harl::*(Harl::ptmem)[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
Harl::Harl()
{}

Harl::~Harl()
{}

void   Harl::complain( std::string level )
{
    int i = 0;
    std::string inp [4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i < 4)
    {
        if (inp[i] == level)
        {
            (this->*ptmem[i])();
            return ;
        }
        i++;
    }
    std::cout << "invalid input\n";
    return ;
}

void    Harl::debug(void)
{
    std::cout << "i wish i have more blackhole days" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "we earn a lot of blackhole days from cpp pool" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "cuz we face new language i think we need more time" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "who can explained why cheaters cheat?" << std::endl;
}