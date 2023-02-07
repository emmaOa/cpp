/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:18:37 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/07 19:00:16 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "constructor with parameter called\n";
    try{
        throw grade;
    }
    catch (int grade){
        if (grade < 1)
            std::cout << "Bureaucrat::GradeTooHighException\n";
        else if (grade > 150)
            std::cout << "Bureaucrat::GradeTooLowException\n";
    } 
    _grade = grade;   
}

std::string Bureaucrat::getName()
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void Bureaucrat::increment_b()
{
    try{
        _grade--;
        throw _grade;
    }
    catch (int _grade){
        if (_grade < 1)
            std::cout << "Bureaucrat::GradeTooHighException\n";
        else if (_grade > 150)
            std::cout << "Bureaucrat::GradeTooLowException\n";
    }
}

void Bureaucrat::decrement_b()
{
    try{
        _grade++;
        throw _grade;
    }
    catch (int _grade){
        if (_grade < 1)
            std::cout << "Bureaucrat::GradeTooHighException\n";
        else if (_grade > 150)
            std::cout << "Bureaucrat::GradeTooLowException\n";
    }
}
std::ostream &operator<<(std::ostream &ret, Bureaucrat &a)
{
    ret << a.getName() << ", bureaucrat grade " << a.getGrade() << "\n";
    return ret;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called\n";
}