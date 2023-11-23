#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class Character : public ICharacter
{
 private:
	int			itemsDropped;
	AMateria*	floor[40];
	AMateria*	inventory[4];
	std::string	name;

 public:
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	Character(void);
	Character(std::string name);
	Character(const Character& obj);
	Character& operator=(const Character& obj);
	~Character(void);
};
