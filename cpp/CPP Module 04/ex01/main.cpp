#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	Animal* animals[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete animals[i];
	std::cout << std::endl;

	std::string str;

	Dog *doggo = new Dog();
	Dog *donggo = new Dog();

	str = doggo->getBrain()->getIdea(0);
	std::cout << "Doggo's has an idea. He says: " << std::endl;

	doggo->getBrain()->setIdea("I want to eat a nuke and explode in the night sky to create the best fireworks ever!!!", 0);
	str = doggo->getBrain()->getIdea(0);
	std::cout << "Doggo's has an idea. He says: "<< str << std::endl;

	*donggo = *doggo;
	str = donggo->getBrain()->getIdea(0);
	std::cout << "Donggo's has an idea. He says: "<< str << std::endl;
	std::cout << std::endl;

	delete doggo;
	delete donggo;

	return 0;
}