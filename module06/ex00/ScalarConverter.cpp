#include <cstring>
#include <limits>
#include <sstream>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

static t_type	getType(const std::string literal)
{
	size_t	i = 0;
	while (std::isspace(literal[i]) != 0)
		i++;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (literal[i] == '\0')
		return (STRING);
	bool	has_point = 0;
	if (std::strncmp(&literal[i], "inf", 3) == 0 || std::strncmp(&literal[i], "nan", 3) == 0)
	{
		has_point = 1;
		i += 3;
	}
	else
	{
		int	digit_before_point = std::isdigit(literal[i]);
		while (std::isdigit(literal[i]) != 0)
			i++;
		if (literal[i] == '.' || literal[i] == 'e')
			has_point = 1;
		if (has_point == 1)
		{
			if (literal[i] == '.')
				i++;
			if (std::isdigit(literal[i]) == 0 && digit_before_point == 0)
				return (STRING);
			while (std::isdigit(literal[i]))
				i++;
			if (literal[i] == 'e')
			{
				i++;
				if (literal[i] == '+' || literal[i] == '-')
					i++;
				if (std::isdigit(literal[i]) == 0)
					return (STRING);
				while (std::isdigit(literal[i]) != 0)
					i++;
			}
		}
	}
	bool	is_float = 0;
	if (has_point == 1 && literal[i] == 'f')
	{
		is_float = 1;
		i++;
	}
	while (std::isspace(literal[i]) != 0)
		i++;
	if (literal[i] == '\0')
	{
		if (is_float == 1)
			return (FLOAT);
		else if (has_point == 1)
			return (DOUBLE);
		else
			return (INTEGER);
	}
	else
		return (STRING);
}

static bool	is_round(const std::string& literal)
{
	size_t	i = 0;
	bool	has_digit = 0;
	while (literal[i] != '\0' && literal[i] != '.' && literal[i] != 'e')
	{
		if (std::isdigit(literal[i]) != 0)
			has_digit = 1;
		i++;
	}
	if (literal[i] == '\0')
		return (has_digit);
	else if (literal[i] == '.')
		i++;
	while (literal[i] == '0')
		i++;
	return (std::isdigit(literal[i]) == 0);
}

template <typename TypeTmp, typename Type>
static void	castPrint(const std::string& literal, t_type type)
{
	TypeTmp	castedTmp;
	if (type == DOUBLE || type == FLOAT)
		castedTmp = std::strtod(literal.c_str(), NULL);
	else if (type == INTEGER)
		castedTmp = std::strtol(literal.c_str(), NULL, 10);
	else
		castedTmp = static_cast<TypeTmp>(literal[0]);
	if (errno == ERANGE
		|| (type == STRING 
			&& (castedTmp > static_cast<long>(std::numeric_limits<char>::max())
				|| castedTmp < static_cast<long>(std::numeric_limits<char>::min())))
		|| (type == FLOAT
			&& (castedTmp > static_cast<double>(std::numeric_limits<float>::max())
				|| castedTmp < static_cast<double>(-std::numeric_limits<float>::max())))
		|| (type == INTEGER
			&& (castedTmp > static_cast<long>(std::numeric_limits<int>::max())
				|| castedTmp < static_cast<long>(-std::numeric_limits<int>::max()))))
	{
		std::cout << "char : impossible" << std::endl << "int : impossible" << std::endl << "float : impossible" << std::endl << "double : impossible" << std::endl;
		return;
	}
	Type	casted;
	casted = static_cast<Type>(castedTmp);
	std::stringstream	stream, streamFP;
	if (type == FLOAT || type == DOUBLE)
		streamFP << static_cast<Type>(casted);
	std::cout << "char : ";
	if ((type == FLOAT || type == DOUBLE || type == INTEGER)
		&& (casted > static_cast<Type>(std::numeric_limits<char>::max())
			|| casted < static_cast<Type>(std::numeric_limits<char>::min())))
		std::cout << "impossible";
	else if (std::isprint(static_cast<char>(casted)) != 0)
	{
		stream << static_cast<char>(casted);
		std::cout << stream.str();
		stream.str("");
	}
	else
		std::cout << "non displayable";
	std::cout << std::endl << "int : ";
	if ((type == FLOAT || type == DOUBLE)
		&& (casted > static_cast<Type>(std::numeric_limits<int>::max())
			|| casted < static_cast<Type>(std::numeric_limits<int>::min())))
		std::cout << "impossible";
	else
	{
		stream << static_cast<int>(casted);
		std::cout << stream.str();
		stream.str("");
	}
	std::cout << std::endl << "float : ";
	if (type == DOUBLE
		&& (casted > static_cast<Type>(std::numeric_limits<float>::max())
			|| casted < static_cast<Type>(-std::numeric_limits<float>::max())))
		std::cout << "impossible";
	else
	{
		stream << static_cast<float>(casted);
		std::cout << stream.str();
		if (is_round(stream.str()) == 1 && stream.str().find("e") == std::string::npos)
			std::cout << ".0";
		stream.str("");
		std::cout << "f";
	}
	std::cout << std::endl << "double : ";
	stream << static_cast<double>(casted);
	std::cout << stream.str();
	if (is_round(stream.str()) == 1 && stream.str().find("e") == std::string::npos)
		std::cout << ".0";
	stream.str("");
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string literal)
{
	t_type	type = getType(literal);
	if (type == STRING && literal.length() == 1)
		castPrint<long, char>(literal, type);
	else if (type == INTEGER)
		castPrint<long, int>(literal, type);
	else if (type == FLOAT)
		castPrint<double, float>(literal, type);
	else if (type == DOUBLE)
		castPrint<double, double>(literal, type);
	else
		std::cout << "char : impossible" << std::endl << "int : impossible" << std::endl << "float : impossible" << std::endl << "double : impossible" << std::endl;
}
