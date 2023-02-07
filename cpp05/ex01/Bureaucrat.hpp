#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>


class Bureaucrat
{
    private:
        int _grade;
        std::string const _name;
    public:
        Bureaucrat(std::string name, int grade);
        std::string getName();
        int getGrade();
        void increment_b();
        void decrement_b();
        ~Bureaucrat();
};
std::ostream &operator<<(std::ostream &ret, Bureaucrat &a);

# endif