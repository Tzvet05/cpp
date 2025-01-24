#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& diamondtrap);
		DiamondTrap& operator=(const DiamondTrap&);
		~DiamondTrap(void);

		DiamondTrap(const std::string name);

		void	attack(const std::string& target);

		void	whoAmI(void);
	private:
		std::string	_name;
};

#endif
