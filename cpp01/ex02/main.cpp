/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:31:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/05 20:37:21 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the string variable : " << &str << std::endl;
    std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;
    
    std::cout << "The value of the string variable : " << str << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
}