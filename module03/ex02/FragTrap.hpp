#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include <string>
#include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap& fragtrap);
		FragTrap& operator=(const FragTrap&);
		~FragTrap(void);

		FragTrap(const std::string name);

		void	highFivesGuys(void);
};

#endif
