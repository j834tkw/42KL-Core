#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string zomzom = "HI THIS IS BRAIN";
    string *stringPTR = &zomzom;
    string &stringREF = zomzom;

    cout << &zomzom << endl;
    cout << &stringPTR << endl;
    cout << &stringREF << endl;

	cout << endl;

    cout << zomzom << endl;
    cout << *stringPTR << endl;
    cout << stringREF << endl;
}

// A pointer in C++ is a variable that holds the memory address of another variable.
// 	- A pointer can be re-assigned.
// 	- A pointer has its own memory address and size on the stack.
// 	- A pointer can be assigned NULL directly

// A reference is an alias for an already existing variable. Once a reference is initialized to a variable, 
// it cannot be changed to refer to another variable.
// 	- A reference cannot be re-assigned, and must be assigned at initialization.
// 	- A reference shares the same memory address with the original variable and takes up no space on the stack.
// 	- A reference cannot be assigned NULL directly