#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

int main(int ac, char **av)
{
	if (ac == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}

	for (int i = 1; av[i]; i++)
		for (int j = 0; av[i][j]; j++)
			putchar(toupper(av[i][j]));
	cout << endl;

	return (0);
}