#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
#include "Brain.hpp"
 
class   Cat  : public Animal{
	private:
		Brain* _cat_brain;
    public:
		Cat (void);
		Cat (const Cat  &obj);
		Cat  &operator=(const Cat  &a);
		void makeSound(void) const;
		~Cat (void);
};

#endif