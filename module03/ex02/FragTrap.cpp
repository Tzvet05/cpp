#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor: \"FragTrap\" created" << std::endl;
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& scavtrap)
{
	std::cout << "FragTrap copy constructor: \"" << scavtrap._name << "\" created" << std::endl;
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap copy assignment constructor: \"" << rhs._name << "\" created" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor: \"" << _name << "\" destroyed" << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "FragTrap custom constructor: \"" << name << "\" created" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap \"" << _name << "\" is down, and therefore cannot ask for a high five anymore" << std::endl;
		return;
	}
	std::cout << "FragTrap \"" << _name << "\" is asking for a high five, guys !" << std::endl;
}
