#include "MyAwesomePhoneBook.hpp"

using std::cout;
using std::endl;
using std::string;

void	PhoneBook::getContact(unsigned int index)
{
	string			firstname;
	string			lastname;
	string			nickname;
	string			phonenum;
	string			darkestsecret;

	cout << "Enter first name: " << endl;
	getline(std::cin, firstname);
	cout << "Enter last name: " << endl;
	getline(std::cin, lastname);
	cout << "Enter nickname: " << endl;
	getline(std::cin, nickname);
	cout << "Enter phone number: " << endl;
	getline(std::cin, phonenum);
	cout << "Enter darkest secret: " << endl;
	getline(std::cin, darkestsecret);

	if (firstname.empty() || lastname.empty() || nickname.empty() || phonenum.empty() || darkestsecret.empty())
		cout << "There are empty field(s). No empty fields allowed. " << endl;
	else
		contact[index].editContact(firstname, lastname, nickname, phonenum, darkestsecret);

	return ;
}

void	PhoneBook::printContact(unsigned int index)
{
	cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  " << endl;

	for (unsigned int i = 0; i++; i < index)
	{
		cout << contact[i].getInfo("firstname") << endl;
	}

	return ;
}