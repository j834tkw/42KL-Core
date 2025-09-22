#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
	private:
		int					value;
		static const int	bits = 8;

	public:
		int		getRawBits(void) const;
		void	setRawBits(int const rawBits);
		Fixed	&operator=(const Fixed &obj);

		int		toInt( void ) const;
		float	toFloat( void ) const;

		Fixed();
		Fixed(int intNum);
		Fixed(float floatNum);
		Fixed(const Fixed &f);
		~Fixed();
};

std::ostream &operator <<(std::ostream &out, const Fixed &fixed);

#endif