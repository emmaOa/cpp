#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
#include "Brain.hpp"
 
class   Animal{
    protected:
        std::string type;
    public:
		Animal();
		Animal(const Animal &obj);
		Animal &operator=(const Animal &a);
		std::string getType(void) const;
		void setType(std::string type);
		virtual void makeSound(void) const;
		virtual ~Animal(void);
};

#endif