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

		bool	operator >(Fixed const &ref) const;
		bool	operator <(Fixed const &ref) const;
		bool	operator >=(Fixed const &ref) const;
		bool	operator <=(Fixed const &ref) const;
		bool	operator ==(Fixed const &ref) const;
		bool	operator !=(Fixed const &ref) const;
	
		Fixed	operator +(Fixed const &ref) const;
		Fixed	operator -(Fixed const &ref) const;
		Fixed	operator *(Fixed const &ref) const;
		Fixed	operator /(Fixed const &ref) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed		&min(Fixed &ref1, Fixed &ref2);
		static Fixed const	&min(Fixed const &ref1, Fixed const &ref2);
		static Fixed		&max(Fixed &ref1, Fixed &ref2);
		static Fixed const	&max(Fixed const &ref1, Fixed const &ref2);

		Fixed();
		Fixed(int intNum);
		Fixed(float floatNum);
		Fixed(const Fixed &f);
		~Fixed();
};

std::ostream &operator <<(std::ostream &out, const Fixed &fixed);

#endif