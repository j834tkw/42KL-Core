#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class AMateria; // AMateria depends on ICharacter and vice-versa, so we need to forward declare one of the classes. This issue is called cross referencing.

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif