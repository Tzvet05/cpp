#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor: \"ClapTrap\" created" << std::endl;
	_name = "ClapTrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap copy constructor: \"" << claptrap._name << "\" created" << std::endl;
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_energyPoints = claptrap._energyPoints;
	_attackDamage = claptrap._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap copy assignment constructor: \"" << rhs._name << "\" created" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor: \"" << _name << "\" destroyed" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap custom constructor: \"" << name << "\" created" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap \"" << _name << "\" is down, and therefore cannot attack anymore" << std::endl;
		return;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap \"" << _name << "\" does not have enough energy points left to attack anymore" << std::endl;
		return;
	}
	std::cout << "ClapTrap \"" << _name << "\" attacks \"" << target << "\" and causes " << _attackDamage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap \"" << _name << "\" is down, and therefore cannot take any points of damage anymore" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
	{
		std::cout << "ClapTrap \"" << _name << "\" loses " << amount - (amount - _hitPoints) << " hitpoints (goes from " << _hitPoints << " to 0) and is now down" << std::endl;
		_hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap \"" << _name << "\" loses " << amount << " hitpoints (goes from " << _hitPoints << " to " << _hitPoints - amount << ")" << std::endl;
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap \"" << _name << "\" is down, and therefore cannot repair itself anymore" << std::endl;
		return;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap \"" << _name << "\" does not have enough energy points left to repair itself anymore" << std::endl;
		return;
	}
	std::cout << "ClapTrap \"" << _name << "\" heals " << amount << " hitpoints (goes from " << _hitPoints << " to " << _hitPoints + amount << ") by using 1 energy point (goes from " << _energyPoints << " to " << _energyPoints - 1 << ")" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}
