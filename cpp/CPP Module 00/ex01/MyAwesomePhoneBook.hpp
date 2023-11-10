#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>

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
		void			printContact(unsigned int index);
};

#endif