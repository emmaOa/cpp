/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:18:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/07 18:59:59 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("imane", 0);
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