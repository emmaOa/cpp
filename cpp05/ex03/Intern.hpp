#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
	    Intern(const Intern &obj);
	    Intern &operator=(const Intern &a);
        AForm* makeForm(std::string n_form, std::string n_target);
        ~Intern();
};

# endif