#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor: \"ScavTrap\" created" << std::endl;
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = 0;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap copy constructor: \"" << scavtrap._name << "\" created" << std::endl;
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
	_guarding = scavtrap._guarding;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap copy assignment constructor: \"" << rhs._name << "\" created" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
		_guarding = rhs._guarding;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor: \"" << _name << "\" destroyed" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "ScavTrap custom constructor: \"" << name << "\" created" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = 0;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap \"" << _name << "\" is down, and therefore cannot attack anymore" << std::endl;
		return;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap \"" << _name << "\" does not have enough energy points left to attack anymore" << std::endl;
		return;
	}
	std::cout << "ScavTrap \"" << _name << "\" attacks \"" << target << "\" and causes " << _attackDamage << " points of damage" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap \"" << _name << "\" is down, and therefore cannot put itself in gate keeper mode anymore" << std::endl;
		return;
	}
	_guarding = !_guarding;
	if (_guarding == 1)
		std::cout << "ScavTrap \"" << _name << "\" is now in gate keeper mode" << std::endl;
}
