#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	private:
		int					value;
		static const int	bits = 8;

	public:
		int		getRawBits(void) const;
		void	setRawBits(int const rawBits);
		Fixed	&operator=(const Fixed &obj);
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();
};

#endif