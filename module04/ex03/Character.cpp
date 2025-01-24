#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void)
{
	_name = "Character";
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_sizeGarbageCollector = 1;
	_nGarbageCollected = 0;
	_garbageCollector = new AMateria*[_sizeGarbageCollector];
}

Character::Character(const Character& character)
{
	_name = character._name;
	for (size_t i = 0; i < 4; i++)
	{
		if (character._inventory[i] != NULL)
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	_sizeGarbageCollector = 1;
	_nGarbageCollected = 0;
	_garbageCollector = new AMateria*[_sizeGarbageCollector];
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (size_t i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (rhs._inventory[i] != NULL)
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (size_t i = 0; i < 4; i++)
		delete _inventory[i];
	for (size_t i = 0; i < _nGarbageCollected; i++)
		delete _garbageCollector[i];
	delete[] _garbageCollector;
}

Character::Character(const std::string name)
{
	_name = name;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_sizeGarbageCollector = 1;
	_nGarbageCollected = 0;
	_garbageCollector = new AMateria*[_sizeGarbageCollector];
}

std::string const &	Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Character \"" << _name << "\": NULL argument: the pointer to the materia to equip is NULL (pointer must point to a materia)" << std::endl;
		return;
	}
	size_t	i = 0;
	while (i < 4 && _inventory[i] != NULL)
		i++;
	if (i == 4)
	{
		std::cout << "Character \"" << _name << "\": inventory full: inventory's 4 slots are already filled with materias (unequip materias to free up slots)" << std::endl;
		return;
	}
	_inventory[i] = m->clone();
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Character \"" << _name << "\": invalid index: inventory only has 4 slots (index must be between 0 and 3, both included)" << std::endl;
		return;
	}
	else if (_inventory[idx] == NULL)
	{
		std::cout << "Character \"" << _name << "\": empty slot: slot at index " << idx << " is empty (slot must contain a materia)" << std::endl;
		return;
	}
	if (_nGarbageCollected == _sizeGarbageCollector)
	{
		AMateria**	newGarbageCollector = new AMateria*[2 * _sizeGarbageCollector];
		for (size_t i = 0; i < _sizeGarbageCollector; i++)
			newGarbageCollector[i] = _garbageCollector[i];
		delete[] _garbageCollector;
		_sizeGarbageCollector *= 2;
		_garbageCollector = newGarbageCollector;
	}
	_garbageCollector[_nGarbageCollected] = _inventory[idx];
	_nGarbageCollected++;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Character \"" << _name << "\": invalid index: inventory only has 4 slots (index must be between 0 and 3, both included)" << std::endl;
		return;
	}
	else if (_inventory[idx] == NULL)
	{
		std::cout << "Character \"" << _name << "\": empty slot: slot at index " << idx << " is empty (slot must contain a materia)" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
