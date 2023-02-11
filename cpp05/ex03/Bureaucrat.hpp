#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        int _grade;
        std::string const _name;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
    	Bureaucrat &operator=(const Bureaucrat &a);
        std::string getName();
        int getGrade() const;
        void increment_b();
        void decrement_b();
        void signForm(const AForm &f);
        void executeForm(AForm const & AForm);
        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };
        ~Bureaucrat();
};
std::ostream &operator<<(std::ostream &ret, Bureaucrat &a);

# endif