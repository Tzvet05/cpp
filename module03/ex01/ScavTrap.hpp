#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include <string>
#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap(void);

		ScavTrap(const std::string name);

		void	attack(const std::string& target);
		void	guardGate(void);
	private:
		bool	_guarding;
};

#endif
