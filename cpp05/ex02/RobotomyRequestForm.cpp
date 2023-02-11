/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:09 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 18:30:45 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45)
{
    std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
    std::cout << "RobotomyRequestForm Copy assignment operator called\n";
    _target = a._target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("robotomy request", 72, 45)
{
    std::cout << "RobotomyRequestForm Copy constructor called\n";
    *this = obj;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45)
{
    _target = target;
    std::cout << "RobotomyRequestForm constructor with parameter called\n";
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    try{
        if (executor.getGrade() <= this->getGrade_exc())
        {
            int i;
            std::cout << "drilling :)\n";
            srand(time(0));
            i = (rand() % 2);
            if (i == 1)
                 std::cout << _target << " has been robotomized successfully\n";
            else
                std::cout << _target << " the robotomy failed\n";
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

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called\n";
}