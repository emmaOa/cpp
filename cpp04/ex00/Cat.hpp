#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
 
class   Cat  : public Animal{
    public:
		Cat (void);
		Cat (const Cat  &obj);
		Cat  &operator=(const Cat  &a);
		void makeSound(void) const;
		~Cat (void);
};

#endif