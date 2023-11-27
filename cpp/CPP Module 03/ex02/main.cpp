#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap	amogus("amogus");
	FragTrap	sussybaka;
	
	sussybaka = amogus;

	sussybaka.attack("himself (SUSuga amogus sensei)");
	sussybaka.takeDamage(30);
	sussybaka.beRepaired(10);
	sussybaka.highFivesGuys();
}