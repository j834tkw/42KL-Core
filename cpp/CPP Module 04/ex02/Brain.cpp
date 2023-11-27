#include "Brain.hpp"

using std::cout;
using std::endl;
using std::string;

void Brain::setIdea(string idea, int index)
{
	this->ideas[index] = idea;
}

string Brain::getIdea(int index)
{
	return (this->ideas[index]);
}

Brain::Brain()
{
	cout << "[Brain] Default constructor called" << endl;
}

Brain::Brain(const Brain &Brain)
{
	cout << "[Brain] Copy constructor called" << endl;
	*this = Brain;
}

Brain &Brain::operator = (const Brain &Brain)
{
	cout << "[Brain] Copy assignment operator called" << endl;
	if (this == &Brain)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = Brain.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	cout << "[Brain] Destructor called" << endl;
}
