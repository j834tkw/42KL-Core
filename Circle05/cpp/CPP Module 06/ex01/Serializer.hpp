#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>
// #include <cstdint> // bruh hv to use -std=c++11 for this

using std::string;
using std::endl;
using std::cout;

struct Data
{
	int			num;
	char		cha;
	string		msg;
};

class Serializer
{
	private:
		Serializer();

	public:
		static uintptr_t	serialize(Data *data);
		static Data*		deserialize(uintptr_t data);

		Serializer(const Serializer &obj);
		Serializer &operator = (const Serializer &obj);
		~Serializer();
};

#endif