#include "Character.hpp"

using std::cout;
using std::endl;
using std::string;

string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	cout << this->name << "'s inventory is full" << endl;
}

void Character::unequip(int idx)
{
	if (this->inventory[idx] == NULL || idx < 0 || idx > 3)
		cout << this->getName() << " doesn't have any item in slot no." << idx << endl;
	else
	{
		floor[itemsDropped] = inventory[idx];
		itemsDropped++;
		if (itemsDropped == 40)
			itemsDropped = 0;
		inventory[idx] = NULL;
		cout << this->getName() << " unequipped an item from slot no." << idx << endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx] != NULL)
		inventory[idx]->use(target);
	else
		cout << "Nothing is equipped in slot no." << idx << endl;
	return ;
}

/*==================================================================================================*/
/*								Canonical Orthodox stuff idk										*/
/*==================================================================================================*/

Character::Character(void)
{
	itemsDropped = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 40; i++)
		this->floor[i] = NULL;
}

Character::Character(string name)
{
	itemsDropped = 0;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 40; i++)
		this->floor[i] = NULL;
}

Character::Character(const Character &Character)
{
	itemsDropped = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 40; i++)
		this->floor[i] = NULL;
	*this = Character;
}

Character &Character::operator = (const Character &obj)
{
	if (this == &obj)
		return (*this);
	this->name = obj.name;
	for (int i = 0; i < 40; i++)
		this->inventory[i] = obj.inventory[i];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	for (int i = 0; i < 4; i++)
		if (this->floor[i])
			delete this->floor[i];
}
