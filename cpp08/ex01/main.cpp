/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:12:56 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/16 15:57:51 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::vector<int> v2;

    for(int i = 0; i < 10000 ; i++)
        v2.push_back(i);
    sp.add_range(v2);

    // try{  
    //     sp.addNumber(11);
    // }
    // catch(std::invalid_argument& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // try{
    //     std::cout << sp.shortestSpan() << std::endl;
    // }
    // catch(std::invalid_argument& e)
    // {
    //             std::cerr << e.what() << std::endl;
    // }

    
    // try{
    //     std::cout << sp.longestSpan() << std::endl;
    // }
    // catch(std::invalid_argument& e)
    // {
    //             std::cerr << e.what() << std::endl;
    // }
return 0;
}