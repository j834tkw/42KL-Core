#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
 protected:
	std::string type;

 public:
	virtual void makeSound(void) const;
	std::string getType(void) const;

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal& operator=(const WrongAnimal& obj);
	virtual ~WrongAnimal(void);
};

#endif