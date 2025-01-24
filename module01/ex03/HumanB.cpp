#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void )
{
	std::string	weapon;

	if (_weapon == NULL)
		weapon = "bare fists";
	else
		weapon = _weapon->getType();
	std::cout << _name << " attacks with their " << weapon << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}
