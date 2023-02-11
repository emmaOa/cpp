/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:13:10 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 17:10:31 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low\n"; 
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high\n"; 
}

Form::Form() : _name("name"), _grade_sgn(0), _grade_exc(0)
{
    std::cout << "constructor called\n";
}

Form::Form(std::string name, const int grade_sgn, const int grade_exc) : _name(name), _grade_sgn(grade_sgn), _grade_exc(grade_exc)
{
	std::cout << "Form constructor with parameter called\n";
    if (grade_sgn < 1 || grade_exc < 1)
        throw Form::GradeTooHighException ();
    else if (grade_sgn > 150 || grade_exc > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &a)
{
    std::cout << "Form Copy assignment operator called\n";
    _is_signde = a._is_signde;
    return *this; 
}

Form::Form(const Form &obj) : _name(obj._name), _grade_sgn(obj._grade_sgn), _grade_exc(obj._grade_exc)
{
    std::cout << "Form Copy constructor called\n";
    *this = obj;
}

std::string Form::getName() const
{
    return _name;
}
bool Form::geIs_signde() const
{
    return _is_signde;
}
int Form::getGrade_sgn() const
{
    return _grade_sgn;
}
int Form::getGrade_exc() const
{
    return _grade_exc;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->getGrade_sgn())
    	_is_signde = true;
    else
    	throw(Form::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &ret, const Form &a)
{
    ret << a.getName() << ", if signde : " << a.geIs_signde() << ", grade required to sign it " << a.getGrade_sgn() << ",  grade required to execute it " << a.getGrade_exc() << "\n";
    return ret;
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}
