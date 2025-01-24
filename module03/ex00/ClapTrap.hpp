#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap& operator=(const ClapTrap&);
		~ClapTrap(void);

		ClapTrap(const std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private:
		std::string	_name;
		size_t		_hitPoints;
		size_t		_energyPoints;
		size_t		_attackDamage;
};

#endif
