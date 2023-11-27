#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* randoAnimal = new Animal(); // compile unsuccessfuller
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
	std::cout << notCatto->getType() << " " << std::endl;
	notCatto->makeSound();
	std::cout << std::endl;

	delete doggo;
	delete catto;
	delete notCatto;
	return 0;
}

// A pure virtual function is a virtual function that is used when the designer of the class wants to force derived classes to override the function 
// and provide their own implementation.

// If a class contains any pure virtual functions, it is considered an "abstract" class and instances of that class cannot be instantiated.

// C++ uses the special syntax = 0; to indicate pure virtual functions instead of adding a new keyword to the language (as languages like C# do). 
// You can think of it as setting the function pointer to 0.