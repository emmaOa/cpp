#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string _name;
		bool _is_signde;
		const int _grade_sgn;
		const int _grade_exc;
	public:
		AForm();
		AForm(std::string name, const int grade_sgn, const int grade_exc);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &a);
		std::string getName() const;
		bool geIs_signde() const;
		int getGrade_sgn() const;
		int getGrade_exc() const;
		void beSigned(const Bureaucrat &b);
		virtual bool execute(Bureaucrat const & executor) const = 0;
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
		virtual	~AForm();
};
std::ostream &operator<<(std::ostream &ret, const AForm &a);

# endif