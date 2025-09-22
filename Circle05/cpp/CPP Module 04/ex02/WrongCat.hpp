#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	public:
		void makeSound(void) const;
//		std::string getType(void) const;

		WrongCat(void);
		WrongCat(const WrongCat& obj);
		WrongCat& operator=(const WrongCat& obj);
		~WrongCat(void);
};

#endif