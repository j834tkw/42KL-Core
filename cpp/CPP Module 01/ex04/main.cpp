#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Usage: ./main <filename> <string to replace> <string to replace with>" << endl;
		return (0);
	}

	string s1 = argv[2];
	string s2 = argv[3];

	return (0);
}