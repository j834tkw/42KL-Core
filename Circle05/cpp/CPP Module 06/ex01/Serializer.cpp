#include "Serializer.hpp"

using std::cout;
using std::endl;
using std::string;

// reinterpret_cast is a type of casting operator used in C++.
// It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different.
// It does not check if the pointer type and data pointed by the pointer is same or not.
// It doesn’t have any return type. It simply converts the pointer type.
// It takes only one parameter i.e., the source pointer variable.

uintptr_t Serializer::serialize(Data *data) // to send information about objects or pointers of the structure or class being used, 
{											// the information must be converted to a basic data type, which is called serialization.

	return (reinterpret_cast<uintptr_t>(data)); // converts pointer to Data to unsigned int
}

Data* Serializer::deserialize(uintptr_t data)
{
	return (reinterpret_cast<Data *>(data)); // converts unsigned int to pointer to data
}

// akin to converting data into a value that can be sent to the network, receiving it, and converting it back into the original data

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

Serializer::Serializer()
{
	cout << "[Serializer] Default constructor called" << endl;
}

Serializer::Serializer(const Serializer &obj)
{
	cout << "[Serializer] Copy constructor called" << endl;
	*this = obj;
}

Serializer &Serializer::operator = (const Serializer &obj)
{
	cout << "[Serializer] Copy assignment operator called" << endl;
	if (this == &obj)
		return (*this);
	(void) obj;
	return (*this);
}

Serializer::~Serializer()
{
	cout << "[Serializer] Destructor called" << endl;
}
