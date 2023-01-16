/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:56 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/16 13:10:07 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl obj_harl;
    std::string lv;

    std::cout << "your level please :" << std::endl;
    std::cin >> lv;
    obj_harl.complain(lv);
    
}