/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:18:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 18:17:42 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat b1("imane", 137);

    // PresidentialPardonForm p1("p1");
    // p1.execute(b1);
    
    // b1.executeForm(p1);


    // RobotomyRequestForm r1("r1");
    // r1.execute(b1);
    
    // b1.executeForm(r1);
    
    
    ShrubberyCreationForm s1("s1");
    s1.execute(b1);

    b1.executeForm(s1);
    
}