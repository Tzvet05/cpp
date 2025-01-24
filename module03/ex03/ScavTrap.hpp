#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include <string>
#include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap& operator=(const ScavTrap&);
		virtual ~ScavTrap(void);

		ScavTrap(const std::string name);

		void	attack(const std::string& target);
		void	guardGate(void);
	protected:
		bool	_guarding;
};

#endif
