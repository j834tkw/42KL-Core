#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	cresont("Cresont");
	ScavTrap	quaso;
	
	quaso = cresont;

	quaso.attack("a not innocent pedestrian");
	quaso.takeDamage(20);
	quaso.beRepaired(20);
	quaso.guardGate();
}