#include "iter.hpp"

using std::endl;
using std::cout;
using std::string;

void	multiplyTwo(int &i)
{
	i *= 2;
}

void	appendStuff(std::string &str)
{
	str.append(" is a retard frog");
}

void	gacha(std::string &name)
{
	int pullSSR = rand() % 10; // 10% chance for ssr
	int fiftyfifty = rand() % 2;

	cout << name << " did a single pull, they";

	if (pullSSR == 0)
	{
		cout << " got an SSR!!! And they";
		if (fiftyfifty)
			cout << " won the 50/50!!! Congrats you lucky bastard" << endl;
		else
			cout << " unfortunately lost the 50/50. :qiqided:" << endl;
	}
	else
		cout << " got trash, so sed" << endl;
}

int main(void)
{
	// basic tests----------------------------------------------------
	// int		intArr[] = {0, 100, 69, -10, 1234567};
	// string	strArr[] = {"Ei", "Eh", "Oi", "Wei", "May i seek your attention, good sir?"};
		
	// iter(intArr, 5, multiplyTwo);
	// for (int i = 0; i < 5; i++)
	// 	cout << intArr[i] << ", ";
	// cout << endl;

	// iter(strArr, 5, appendStuff);
	// for (int i = 0; i < 5; i++)
	// 	cout << "Chan beammmmm~~~~~~~ Now " << strArr[i] << endl;

	// its gacha time-------------------------------------------------
	srand(time(0));
	string	nameArr[] = {"Amogus", "Sussybaka", "Imposter", "Mogumogus", "Sas"};
	iter(nameArr, 5, gacha); // same results may appear if spam too fast, so spam slower, preferably once every sec

	return (0);
}