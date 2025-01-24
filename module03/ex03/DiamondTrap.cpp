#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor: \"DiamondTrap\" created" << std::endl;
	_name = "DiamondTrap";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap)
{
	std::cout << "DiamondTrap copy constructor: \"" << diamondtrap._name << "\" created" << std::endl;
	_name = diamondtrap._name;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = diamondtrap._hitPoints;
	_energyPoints = diamondtrap._energyPoints;
	_attackDamage = diamondtrap._attackDamage;
	_guarding = diamondtrap._guarding;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap copy assignment constructor: \"" << rhs._name << "\" created" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		ClapTrap::_name = _name + "_clap_name";
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
		_guarding = rhs._guarding;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor: \"" << _name << "\" destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
{
	std::cout << "DiamondTrap custom constructor: \"" << name << "\" created" << std::endl;
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

void	DiamondTrap::whoAmI(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << "DiamondTrap \"" << _name << "\" is down, and therefore cannot provide their ClapTrap name anymore" << std::endl;
		return;
	}
	std::cout << "DiamondTrap \"" << _name << "\" has a ClapTrap name \"" << ClapTrap::_name << "\"" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
