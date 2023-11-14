#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << std::endl << "DEBUG: ";
	harl.complain("DEBUG");
	std::cout << std::endl << "INFO: ";
	harl.complain("INFO");
	std::cout << std::endl << "WARNING: ";
	harl.complain("WARNING");
	std::cout << std::endl << "ERROR: ";
	harl.complain("ERROR");
	std::cout << std::endl;

	return (0);
}
