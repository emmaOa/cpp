#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Form
{
	private:
		const std::string _name;
		bool _is_signde;
		const int _grade_sgn;
		const int _grade_exc;
	public:
		Form(std::string name, const int grade_sgn, const int grade_exc);
		~Form();
};
// std::ostream &operator<<(std::ostream &ret, Form &a);

# endif