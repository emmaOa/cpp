#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        static const int _fract_nb = 8 ;
        int	_fixed_nb;
	public:
		Fixed();
		Fixed(Fixed const &obj);
		Fixed &operator=(Fixed const &a);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed(void);
};

#endif