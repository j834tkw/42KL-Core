#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		AMateria *clone() const;
		void use(ICharacter &target);

		Ice();
		Ice(const Ice &ori);
		~Ice();
		Ice &operator=(const Ice &ori);
};

#endif