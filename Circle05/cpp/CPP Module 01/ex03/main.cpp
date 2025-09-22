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

// HumanA and HumanB have the same name and Weapon, but A must own the Weapon when it is created, and B does not necessarily have to own it.

// In the case of HumanA, when receiving the club argument from the constructor, it is received as a reference or value rather than a pointer. 
// HumanA will store the weapon's memory address and any changes in weapon will reflect on HumanA's weapon.

// When you have a member in your class that is a reference, you must initialize it in the constructor, ie using a member initializer list.

// In the case of HumanB, it does not receive any arguments other than name from the constructor, so it will not be a reference as references does 
// not allow NULL.
