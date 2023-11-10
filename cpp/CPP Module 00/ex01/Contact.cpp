#include "MyAwesomePhoneBook.hpp"

void	Contact::editContact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string darkestsecret)
{
	this->_firstName.assign(firstname);
	this->_lastName.assign(lastname);
	this->_nickName.assign(nickname);
	this->_phoneNum.assign(phonenum);
	this->_darkestSecret.assign(darkestsecret);
}

std::string		Contact::getInfo(std::string target)
{
	if (target == "firstname")
		return (_firstName);
	else if (target == "lastname")
		return (_lastName);
	else if (target == "nickname")
		return (_nickName);
	else if (target == "phonenum")
		return (_phoneNum);
	else if (target == "darkestsecret")
		return (_darkestSecret);
	else
		return ("");
}
