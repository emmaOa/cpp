/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:07:59 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/10 19:05:52 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called\n";
}

Intern &Intern::operator=(const Intern &a)
{
    (void)a;
    std::cout << "Intern Copy assignment operator called\n";
    return *this;
}

Intern::Intern(const Intern &obj)
{
    std::cout << "Intern Copy constructor called\n";
    *this = obj;
}

AForm* Intern::makeForm(std::string n_form, std::string n_target)
{
    std::string inp [3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* rrf[3];
    rrf[0] = new ShrubberyCreationForm(n_target);
    rrf[1] = new RobotomyRequestForm(n_target);
    rrf[2] = new PresidentialPardonForm(n_target);
    
    int i = 0;
    while (i < 3 && inp[i] != n_form)
    {
       i++;
    }
    if (i == 3)
    {
        for (int j = 0; j < 3; j++)
        {
                delete rrf[j];
        }
        std::cout << "we don't have fore namet " << n_form << "\n";
        return (NULL);
    }
    for (int j = 0; j < 3; j++)
    {
        if (j != (i - 1))
            delete rrf[j];
    }
    std::cout << "Intern creates " << n_form << "\n";
    return (rrf[i - 1]);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called\n";
}
