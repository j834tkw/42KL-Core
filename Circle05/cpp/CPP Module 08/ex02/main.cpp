#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "e:" << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "e:" << mstack.size() << std::endl;

	for (int i = 0; i < 1000; i++)
		mstack.push(i);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	++it;
	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }

	std::stack<int> s(mstack);
	MutantStack<int>::iterator sit = mstack.begin();
	MutantStack<int>::iterator site = mstack.end();
	while (sit != site)
	{
		std::cout << *sit << std::endl;
		++sit;
	}
	std::cout << "Lesgo" << std::endl; 
	return 0;
}