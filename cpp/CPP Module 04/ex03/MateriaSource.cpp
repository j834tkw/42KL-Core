#include "MateriaSource.hpp"

using std::cout;
using std::endl;
using std::string;

void MateriaSource::learnMateria(AMateria* type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i] == NULL)
		{
			this->memory[i] = type;
			return ;
		}
	}
	cout << "No memory left to learn " << type->getType() << endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == memory[i]->getType() && memory[i])
			return (memory[i]->clone()); // clone has new, subject pdf says createMateria returns a new Materia
	}
	cout << "Materia not learnt" << endl;
	return (NULL);
}

/*==================================================================================================*/
/*								Canonical Orthodox stuff idk										*/
/*==================================================================================================*/

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &MateriaSource)
{
	*this = MateriaSource;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
		this->memory[i] = obj.memory[i];
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++) // subject pdf has new in learnMateria(...), so have to delete those too
		if (memory[i])
			delete memory[i];
}
