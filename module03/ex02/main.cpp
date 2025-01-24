#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap, boop("Boop"), meep("Meep");

	clap.attack("Boop");
	boop.takeDamage(0);
	boop.beRepaired(5);
	boop.attack("ClapTrap");
	clap.takeDamage(5);
	boop.attack("ClapTrap");
	clap.takeDamage(5);
	clap.attack("Boop");
	clap.beRepaired(10);
	boop.attack("ClapTrap");
	clap.takeDamage(5);
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

	ScavTrap	scav, otto("Otto"), mima("Mi-Ma");

	scav.attack("Otto");
	otto.takeDamage(5);
	otto.beRepaired(5);
	mima.guardGate();
	mima.guardGate();
	mima.attack("ScavTrap");
	scav.takeDamage(100);
	scav.guardGate();

	FragTrap	frag, stinky("Stinky");

	frag.attack("Stinky");
	stinky.takeDamage(100);
	stinky.highFivesGuys();
	return (0);
}
