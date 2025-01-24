#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <string>
#include "Weapon.hpp"

class	HumanA {
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );

		void	attack( void );
	private:
		Weapon&		_weapon;
		std::string	_name;
};

#endif
