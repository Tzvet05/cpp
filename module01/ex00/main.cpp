#include "Zombie.hpp"

int	main( void )
{
	randomChump("zombie_stack");
	Zombie* ptr = newZombie("zombie_heap");
	delete ptr;
	return (0);
}
