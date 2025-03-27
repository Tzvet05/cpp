#pragma once

#include <string>

typedef enum	type
{
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	NONE
}	t_type;

class	ScalarConverter
{
	public:
		static void	convert(const std::string literal);
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& scalarConverter);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter(void);
};
