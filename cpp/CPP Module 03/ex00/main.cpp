#include "ClapTrap.hpp"

int main()
{
	ClapTrap wanker("wanker");
	ClapTrap yoinker("yoinker");

	ClapTrap wankiwanker = wanker;
	wanker.attack("yoinker");
	yoinker.takeDamage(0);
	yoinker.beRepaired(5);
	wankiwanker.attack("wanker");
	wanker.takeDamage(10);
	wanker.beRepaired(10); //cant act since the 10hp of wanker -10, so he got skulled
}