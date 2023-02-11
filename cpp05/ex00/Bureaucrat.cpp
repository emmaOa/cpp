/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:18:37 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 16:56:39 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low\n"; 
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high\n"; 
}

Bureaucrat::Bureaucrat() : _name("name")
{
    std::cout << "constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "constructor with parameter called\n";
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;   
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a)
{
    std::cout << "Bureaucrat Copy assignment operator called\n";
    _grade = a._grade;
    return *this; 
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name)
{
    std::cout << "Bureaucrat Copy constructor called\n";
    *this = obj;
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
     _grade--;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrement_b()
{
    _grade++;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
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