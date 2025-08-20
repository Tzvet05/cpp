#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Too few arguments (exactly 1 argument is required)" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cerr << "Too many arguments (exactly 1 argument is required)" << std::endl;
		return (1);
	}
	ScalarConverter::convert(std::string(argv[1]));
	return (0);
}
