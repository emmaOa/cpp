#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        static const int _fract_nb = 8 ;
        int	_fixed_nb;
	public:
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &a);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed(void);
};
std::ostream &operator<<(std::ostream &ret, const Fixed &a);

#endif