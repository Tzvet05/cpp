#include <iostream>
#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: too few arguments provided (must be ./RPN \"[expression]\")" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cerr << "Error: too many arguments provided (must be ./RPN \"[expression]\")" << std::endl;
		return (1);
	}
	try
	{
		RPN	rpn;
		std::cout << rpn.process(std::string(argv[1])) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
