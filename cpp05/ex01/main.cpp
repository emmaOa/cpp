/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:18:33 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 17:13:00 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    Bureaucrat b1("imane", 1);
    try{
        Form f1("form1", 151, 100);
    }
    catch(Form::GradeTooLowException& e){
        std::cerr << e.what();
    }
    /// 
    try{
        Form f1("form1", 0, 100);
    }
    catch(Form::GradeTooHighException& e){
        std::cerr << e.what();
    }
    
    Form f1("form1", 150, 100);
    try{
       f1.beSigned(b1);
    }
    catch(Form::GradeTooHighException& e){
        std::cerr << e.what();
    }
    // f1.beSigned(b1);
    // Form f2("form2", 5, 100);
    // f2.beSigned(b1);
    // b1.signForm(f1);
    // b1.signForm(f2);
    // std::cout << f1;
}