#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: too few arguments provided (must be ./btc [infile])" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cerr << "Error: too many arguments provided (must be ./btc [infile])" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	exchange_rates;
		exchange_rates.calculateValues(std::string(argv[1]));
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
