#include <limits>
#include <sstream>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

static void	printImpossible(void)
{
	std::cout << "Char :   Impossible" << std::endl << "Int :    Impossible" << std::endl
	<< "Float :  Impossible" << std::endl << "Double : Impossible" << std::endl;
}

static t_type	getType(const std::string literal)
{
	char*	end;
	if (literal.length() == 1
		&& ((literal[0] >= 32 && literal[0] <= 47)
			|| (literal[0] >= 58 && literal[0] <= 126)))
		return (CHAR);
	std::strtoll(literal.c_str(), &end, 10);
	if (literal.find_first_not_of("\t\n\v\f\r ",
		(size_t)(end - literal.c_str())) == std::string::npos)
		return (INTEGER);
	std::strtof(literal.c_str(), &end);
	if (end[0] == 'f' && literal.find_first_not_of("\t\n\v\f\r ",
		(size_t)(end - literal.c_str()) + 1) == std::string::npos)
		return (FLOAT);
	std::strtod(literal.c_str(), &end);
	if (literal.find_first_not_of("\t\n\v\f\r ",
		(size_t)(end - literal.c_str())) == std::string::npos)
		return (DOUBLE);
	return (NONE);
}

template <typename Type>
static bool	isRound(Type number)
{
	std::stringstream	stream;
	stream << number;
	if (stream.str().find("e") != std::string::npos
		|| stream.str().find(".") != std::string::npos)
		return (0);
	return (1);
}

template <typename Type>
static void	convertPrint(Type number)
{
	if (errno == ERANGE)
	{
		printImpossible();
		return ;
	}
	std::cout << "Char :   ";
	if (number != number
		|| static_cast<double>(number) < static_cast<double>(std::numeric_limits<char>::min())
		|| static_cast<double>(number) > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "Impossible";
	else if (static_cast<char>(number) < 32 || static_cast<char>(number) > 126)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(number) << "'";
	std::cout << std::endl << "Int :    ";
	if (number != number
		|| static_cast<double>(number) < static_cast<double>(std::numeric_limits<int>::min())
		|| static_cast<double>(number) > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "Impossible";
	else
		std::cout << static_cast<int>(number);
	std::cout << std::endl << "Float :  ";
	if (static_cast<double>(number) != static_cast<double>(std::numeric_limits<float>::infinity())
		&& static_cast<double>(number) != -static_cast<double>(std::numeric_limits<float>::infinity())
		&& (static_cast<double>(number) < static_cast<double>(-std::numeric_limits<float>::max())
		|| static_cast<double>(number) > static_cast<double>(std::numeric_limits<float>::max())))
		std::cout << "Impossible";
	else
	{
		std::cout << static_cast<float>(number);
		if (static_cast<double>(number) != static_cast<double>(std::numeric_limits<float>::infinity())
			&& static_cast<double>(number) != -static_cast<double>(std::numeric_limits<float>::infinity())
			&& number == number && isRound(static_cast<float>(number)) == 1)
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl << "Double : " << static_cast<double>(number);
	if (static_cast<double>(number) != static_cast<double>(std::numeric_limits<double>::infinity())
		&& static_cast<double>(number) != -static_cast<double>(std::numeric_limits<double>::infinity())
		&& number == number && isRound(static_cast<double>(number)) == 1)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string literal)
{
	if (literal.length() == 0)
	{
		printImpossible();
		return;
	}
	t_type	type = getType(literal);
	errno = 0;
	if (type == CHAR)
		convertPrint<char>(literal[0]);
	else if (type == INTEGER)
		convertPrint<long>(std::strtoll(literal.c_str(), NULL, 10));
	else if (type == FLOAT)
		convertPrint<float>(std::strtof(literal.c_str(), NULL));
	else if (type == DOUBLE)
		convertPrint<double>(std::strtod(literal.c_str(), NULL));
	else
		printImpossible();
}
