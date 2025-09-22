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
		if (this->inventory[i] == NULL) // search for empty inevntory slot of the smallest index, max 4 slot equipped
		{
			this->inventory[i] = m;
			return ;
		}
	}
	cout << this->name << "'s inventory is full" << endl;
}

void Character::unequip(int idx)
{
	if (this->inventory[idx] == NULL || idx < 0 || idx > 3) // if that slot is already empty or idx is out of scope, return error msg
		cout << this->getName() << " doesn't have any item in slot no." << idx << endl;
	else
	{
		floor[itemsDropped] = inventory[idx];
		itemsDropped++;
		if (itemsDropped == 40) // incase some wanker actually equips & unequips over 40 items
			itemsDropped = 0;
		inventory[idx] = NULL; // this inventory slot is now empty, so back to NULL it is
		cout << this->getName() << " unequipped an item from slot no." << idx << endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx] != NULL && (idx >= 0 && idx <= 3)) // if not empty and idx not out of scope, then use
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
	this->name = "User_0001";
	for (int i = 0; i < 4; i++) // initialize inventory
		this->inventory[i] = NULL;
	for (int i = 0; i < 40; i++) // initialize floor
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
	this->name = Character.name;
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
	this->itemsDropped = obj.itemsDropped;
	for (int i = 0; i < 40; i++) // deep copies entire inventory & floor
		this->inventory[i] = obj.inventory[i];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++) // the character may have equipped slots 0, 1, 2 ,3 but then unequips from slot 0, 1 or 2
		if (this->inventory[i]) // so the function goes thru every slot, deleting those that arent empty
			delete this->inventory[i];
	for (int i = 0; i < 4; i++)
		if (this->floor[i])
			delete this->floor[i];
}
