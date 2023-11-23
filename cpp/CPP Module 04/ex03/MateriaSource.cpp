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
		if (type.compare(memory[i]->getType()) == 0)
			return (memory[i]->clone());
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
}
