#include "Zombie.hpp"

int	main( void )
{
	Zombie* horde = zombieHorde(5, "zombie_horde");
	for (size_t i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	horde = zombieHorde(-3, "zombie_horde");
	delete[] horde;
	horde = zombieHorde(0, "zombie_horde");
	delete[] horde;
	return (0);
}
