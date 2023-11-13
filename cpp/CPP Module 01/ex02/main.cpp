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
};