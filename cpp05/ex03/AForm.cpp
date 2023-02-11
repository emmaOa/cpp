/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:13:10 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 18:38:28 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low\n"; 
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high\n"; 
}

AForm::AForm() : _grade_sgn(0), _grade_exc(0)
{
	std::cout << "Form constructor called\n";
}

AForm &AForm::operator=(const AForm &a)
{
    std::cout << "AForm Copy assignment operator called\n";
    _is_signde = a._is_signde;
    return *this; 
}

AForm::AForm(const AForm &obj) : _name(obj._name), _grade_sgn(obj._grade_sgn), _grade_exc(obj._grade_exc)
{
    std::cout << "AForm Copy constructor called\n";
    *this = obj;
}

AForm::AForm(const std::string name, const int grade_sgn, const int grade_exc) : _name(name), _grade_sgn(grade_sgn), _grade_exc(grade_exc)
{
	std::cout << "Form constructor with parameter called\n";
    if (grade_sgn < 1 || grade_exc < 1)
        throw AForm::GradeTooHighException ();
    else if (grade_sgn > 150 || grade_exc > 150)
        throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
    return _name;
}
bool AForm::geIs_signde() const
{
    return _is_signde;
}
int AForm::getGrade_sgn() const
{
    return _grade_sgn;
}
int AForm::getGrade_exc() const
{
    return _grade_exc;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->getGrade_sgn())
    	_is_signde = true;
    else
    	throw(AForm::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &ret, const AForm &a)
{
    ret << a.getName() << ", is signde " << a.geIs_signde() << " grade required to sign it " << a.getGrade_sgn() << "  grade required to execute it " << a.getGrade_exc() << "\n";
    return ret;
}

AForm::~AForm()
{
	std::cout << "Form destructor called\n";
}
