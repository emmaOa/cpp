/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:03:02 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 18:31:29 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5)
{
    std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
    std::cout << "PresidentialPardonForm Copy assignment operator called\n";
    _target = a._target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("presidential pardon", 25, 5)
{
    std::cout << "PresidentialPardonForm Copy constructor called\n";
    *this = obj;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5)
{
    _target = target;
    std::cout << "PresidentialPardonForm constructor with parameter called\n";
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try{
        if (executor.getGrade() <= this->getGrade_exc())
        {
            std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
            return true;
        }
        else
            throw (_target);
    }
    catch(std::string tg)
    {
        std::cout << tg << " have low grade to execute this form\n";
    }
    return false;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called\n";
}