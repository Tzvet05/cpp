#include <iostream>
#include "Harl.hpp"

static int	check_params(int argc)
{
	if (argc < 2)
	{
		std::cerr << "Error: Too few arguments (exactly 1 argument required)" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cerr << "Error: Too many arguments (exactly 1 argument required)" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (check_params(argc) == 1)
		return (1);
	harl.complain(std::string(argv[1]));
	return (0);
}
