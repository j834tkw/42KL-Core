#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* randoAnimal = new Animal();
	const Animal* doggo = new Dog();
	const Animal* catto = new Cat();
	const WrongAnimal* notCatto = new WrongCat();

	std::cout << std::endl;
	std::cout << catto->getType() << " " << std::endl;
	catto->makeSound();
	std::cout << std::endl;
	std::cout << doggo->getType() << " " << std::endl;
	doggo->makeSound();
	std::cout << std::endl;
	std::cout << randoAnimal->getType() << " " << std::endl;
	randoAnimal->makeSound();
	std::cout << std::endl;
	std::cout << notCatto->getType() << " " << std::endl;
	notCatto->makeSound();
	std::cout << std::endl;

	delete randoAnimal;
	delete doggo;
	delete catto;
	delete notCatto;
	return 0;
}

// Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. 
// To correct this situation, the base class should be defined with a virtual destructor. 
