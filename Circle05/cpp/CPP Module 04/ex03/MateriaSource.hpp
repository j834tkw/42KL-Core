#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		void learnMateria(AMateria* type);
		AMateria* createMateria(std::string const & type);

		MateriaSource();
		MateriaSource(const MateriaSource &materiasource);
		MateriaSource &operator = (const MateriaSource &materiasource);
		~MateriaSource();
	
	private:
		AMateria *memory[4];
};