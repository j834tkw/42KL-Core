#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		void makeSound(void) const;
		Brain *getBrain(void);

		Dog(void);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		~Dog(void);
};

#endif