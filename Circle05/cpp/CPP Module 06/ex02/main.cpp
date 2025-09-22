#include "ABC.hpp"
#include "Base.hpp"

using std::cout;
using std::endl;

int main(void)
{
	Base *obj = generate();

	cout << "Whatever* is: ";
	identify(obj); // prints the actual type of the object pointed to by obj
	cout << "Whatever& is: ";
	identify(*obj); // same as above except this one uses a reference instead of a pointer

	delete obj;

	return (0);
}