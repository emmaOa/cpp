/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:10:53 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/11 18:32:26 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
    std::cout << "ShrubberyCreationForm Copy assignment operator called\n";
    _target = a._target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("shrubbery creation", 145, 137)
{
    std::cout << "ShrubberyCreationForm Copy constructor called\n";
    *this = obj;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137)
{
    _target = target;
    std::cout << "ShrubberyCreationForm constructor with parameter called\n";
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    try{
        if (executor.getGrade() <= this->getGrade_exc())
        {
            std::string n2 = "_shrubbery";
            std::ofstream n_file;
            n_file.open(_target + n2);
            if (!n_file.is_open()){
                std::cout << "Open failed" << std::endl;
                exit(1);
            }
            n_file << "                                  # #### ####\n";
            n_file << "                                ### \\/#|### |/####\n";
            n_file << "                               ##\\/#/ \\||/##/_/##/_#\n";
            n_file << "                             ###  \\/###|/ \\/ # ###\n";
            n_file << "                           ##_\\_#\\_\\## | #/###_/_####\n";
            n_file << "                          ## #### # \\ #| /  #### ##/##\n";
            n_file << "                           __#_--###`  |{,###---###-~\n";
            n_file << "                                     \\ }{\n";
            n_file << "                                      }}{\n";
            n_file << "                                      }}{\n";
            n_file << "                                      {{}\n";
            n_file << "                                , -=-~{ .-^- _\n";
            n_file << "                                      `}\n";
            n_file << "                                       {\n";
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

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called\n";
}