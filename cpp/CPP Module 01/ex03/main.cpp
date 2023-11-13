#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

// The Weapon class creates a getType function and a setType function using the string variable type.

// HumanA and HumanB have the same name and Weapon, but A must own the Weapon when it is created, and B does not necessarily have to own it.

// Even if Human does not setWeapon after club becomes setType, its contents must be reflected. Therefore, both human weapons must use 
// pointers or references.

// In the case of HumanA, when receiving the club argument from the constructor, you can see that it is received as a reference or value 
// rather than a pointer. However, if you want to apply the change in the club's setType immediately, it will naturally have to be a reference.

// In the case of HumanB, it does not receive any arguments from the constructor, so it will not be a reference as references does not allow NULL. If 
// you think that the value will not be the same for the above reasons, you can think of the variable as a pointer and the argument of setWeapon 
// as a reference.
