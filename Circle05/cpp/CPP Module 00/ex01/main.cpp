#include "MyAwesomePhoneBook.hpp"

using std::string;
using std::cout;
using std::endl;

int main()
{
	PhoneBook		phonebook;
	string			input;
	unsigned int	index = 0;
	int				fulllist = 0;

	while (1)
	{
		if (index == 8)
		{
			index = 0; // reset index so new adding contact starts from beginning
			fulllist = 1;
		}

		cout << "Enter a command: ";

		std::getline(std::cin, input); // wait & get an input

		if (input == "ADD")
		{
			phonebook.getContact(index);
			index++;
		}
		else if (input == "SEARCH")
			phonebook.printContactList(index, fulllist);
		else if (input == "EXIT")
			break ;
		else
			cout << "Please enter either ADD, SEARCH or EXIT only." << endl;
	}

	return (0);
}
