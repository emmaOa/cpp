#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string _name;
		bool _is_signde;
		const int _grade_sgn;
		const int _grade_exc;
	public:
		Form();
		Form(std::string name, const int grade_sgn, const int grade_exc);
		Form(const Form &obj);
		Form &operator=(const Form &a);
		std::string getName() const;
		bool geIs_signde() const;
		int getGrade_sgn() const;
		int getGrade_exc() const;
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
		void beSigned(const Bureaucrat &b);
		~Form();
};
std::ostream &operator<<(std::ostream &ret, const Form &a);

# endif