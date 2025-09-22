#include "MyAwesomePhoneBook.hpp"

using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::atoi;

void	PhoneBook::getContact(unsigned int index)
{
	string			firstname;
	string			lastname;
	string			nickname;
	string			phonenum;
	string			darkestsecret;

	cout << "Enter first name: ";
	getline(std::cin, firstname);
	cout << "Enter last name: ";
	getline(std::cin, lastname);
	cout << "Enter nickname: ";
	getline(std::cin, nickname);
	cout << "Enter phone number: ";
	getline(std::cin, phonenum);
	cout << "Enter darkest secret: ";
	getline(std::cin, darkestsecret);

	if (firstname.empty() || lastname.empty() || nickname.empty() || phonenum.empty() || darkestsecret.empty()) // check if any field is empty
		cout << "There are empty field(s). No empty fields allowed. " << endl;
	else
	{
		contact[index].editContact(firstname, lastname, nickname, phonenum, darkestsecret);
		cout << "Contact saved." << endl;
	}

	return ;
}

void	PhoneBook::printContactList(unsigned int index, int fulllist)
{
	string			input;
	int				i = 0;

	cout << endl;
	cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << endl;

	for (unsigned int i = 0; i < 8; i++)
	{
		cout << setw(10) << i + 1 << "|";
		cout << setw(10) << truncStr(contact[i].getInfo("firstname")) << "|"; // set width, then trunc according to width set
		cout << setw(10) << truncStr(contact[i].getInfo("lastname")) << "|";
		cout << setw(10) << truncStr(contact[i].getInfo("nickname")) << endl;
	}

	cout << endl;
	cout << "Select an index to display contact: ";
	getline(std::cin, input);
	i = atoi(input.c_str()); // change str to char * so atoi is usable

	if (i < 1 || (i > (int)index && !fulllist) || (i > 8 && fulllist))
		cout << "Invalid index. Exiting SEARCH." << endl;
	else
		printSelectedContact(i);

	return ;
}

std::string		PhoneBook::truncStr(std::string str)
{
	if (str.length() > 10)
		return (str.std::string::substr(0, 9).append("."));

	return (str);
}

void			PhoneBook::printSelectedContact(int contactindex)
{
	int	i = contactindex - 1;

	cout << "First name: " << contact[i].getInfo("firstname") << endl;
	cout << "Last name: " << contact[i].getInfo("lastname") << endl;
	cout << "Nickname: " << contact[i].getInfo("nickname") << endl;
	cout << "Phone number: " << contact[i].getInfo("phonenum") << endl;
	cout << "Darkest secret: " << contact[i].getInfo("darkestsecret") << endl;
}
