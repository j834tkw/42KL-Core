#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// new & delete tests
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	// array of half dog half cat test
	std::cout << std::endl;
	Animal* animals[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete animals[i];
	std::cout << std::endl;

	// deep copy test
	std::string str;

	Dog doggo;

	str = doggo.getBrain()->getIdea(0);
	std::cout << "Doggo's has an idea. He says: " << str << std::endl;
	doggo.getBrain()->setIdea("I want to eat a nuke and explode in the night sky to create the best fireworks ever!!!", 0);
	str = doggo.getBrain()->getIdea(0);
	std::cout << "Doggo's has an idea. He says: "<< str << std::endl;
	std::cout << std::endl;

	Dog donggo = doggo;

	str = donggo.getBrain()->getIdea(0);
	std::cout << "Donggo's has an idea. He says: "<< str << std::endl;
	std::cout << std::endl;

	return 0;
}