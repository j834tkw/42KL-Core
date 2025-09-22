#include "Base.hpp"
#include "ABC.hpp"

using std::cout;
using std::endl;

Base*   generate(void)
{
	srand(time(0)); // seed rng with a different number each time you launch the program by using time as the seed
	int rngNum = rand();

    if (rngNum % 3 == 0)
        return (new A);
    else if ( rngNum % 3 == 1 )
        return (new B);
    else
        return (new C);
}

// Dynamic Cast: A cast is an operator that converts data from one type to another type. In C++, dynamic casting is mainly used for safe 
// downcasting at run time. To work on dynamic_cast there must be one virtual function in the base class. A dynamic_cast works only polymorphic 
// base class because it uses this information to decide safe downcasting.

// Downcasting converts the base class's pointer or reference to the derived class's pointer or reference. It manually cast the base class's 
// object to the derived class's object, so we must specify the explicit typecast.

// Syntax: dynamic_cast <new_type>(Expression)

// for dynamic casting there must be one Virtual function. Suppose If we do not use the virtual function, then what is the result? In that case, it 
// generates an error message “Source type is not polymorphic”.

void identify (Base* p)
{
	if (dynamic_cast<A*>(p)) // returns a value of type A* if the casting is successful, a null pointer if not
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
	else
		cout << "unknown substance" << endl;
}

void identify (Base& p)
{
	try 
	{
		A &a = dynamic_cast<A&>(p); // You cannot verify the success of a dynamic cast using reference types by comparing the result with zero 
		std::cout << "A" << endl;	// because there is no such thing as a null reference
		(void) a;	// the funny unused variable error again
	}
  	catch (std::exception &e) // if the casting fails, an exception occurs
	{
	}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << endl;
		(void) b;
	}
  	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << endl;
		(void) c;
	}
  	catch (std::exception &e)
	{
	}
}

Base::~Base()
{
}