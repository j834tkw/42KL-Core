#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string.h>
#include <cstdlib>

class Contact
{
	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNum;
		std::string		_darkestSecret;
		int				index;

	public:
		void			editContact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string darkestsecret);
		std::string		getInfo(std::string target);
};

class PhoneBook
{
	private:
		Contact			contact[8];

	public:
		void			getContact(unsigned int index);
		void			printContactList(unsigned int index, int fulllist);
		std::string		truncStr(std::string str);
		void			printSelectedContact(int contactindex);
};

#endif