#include "MyAwesomePhoneBook.hpp"

using std::string;
using std::cout;
using std::endl;

int main(int ac, char **av)
{
	PhoneBook		phonebook;
	string			input{};
	unsigned int	index = 0;

	while (1)
	{
		if (index == 8)
			index = 0;
		cout << "Enter a command" << endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.getContact(index);
		else if (input == "SEARCH")
			phonebook.printContact(index);
		else if (input == "EXIT")
			break ;
		index++;
	}
	return (0);
}
