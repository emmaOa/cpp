/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:16:52 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/16 15:39:14 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    for (int i = 1; i <= 5; i++)
        v.push_back(i);
    
    try {
        std::vector<int>::iterator it = easyfind(v, 1);
        std::cout << "Found " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}