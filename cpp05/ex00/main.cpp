/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:18:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/10 23:57:03 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat b1("imane", 150);
        std::cout << b1.getGrade() << "\n";
        std::cout << b1.getName() << "\n";
        b1.increment_b();
        std::cout << b1.getGrade() << "\n";
        b1.decrement_b();
        std::cout << b1.getGrade() << "\n";
        b1.decrement_b();
        std::cout << b1.getGrade() << "\n";
        std::cout << b1;
    }
    catch(std::exception & e){
        std::cerr << e.what();
    }
}
