#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	def, boop("Boop"), meep("Meep");

	def.attack("Boop");
	boop.takeDamage(0);
	boop.beRepaired(5);
	boop.attack("ClapTrap");
	def.takeDamage(5);
	boop.attack("ClapTrap");
	def.takeDamage(5);
	def.attack("Boop");
	def.beRepaired(10);
	boop.attack("ClapTrap");
	def.takeDamage(5);
	meep.attack("Boop");
	boop.takeDamage(20);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.beRepaired(0);
	meep.attack("Boop");
	return (0);
}
