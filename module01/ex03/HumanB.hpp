#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>
#include "Weapon.hpp"

class	HumanB {
	public:
		HumanB( std::string name);
		~HumanB( void );

		void	attack( void );
		void	setWeapon( Weapon& weapon );
	private:
		Weapon*		_weapon;
		std::string	_name;
};

#endif
