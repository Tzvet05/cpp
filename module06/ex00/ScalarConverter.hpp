#pragma once

#include <string>

typedef enum	type
{
	STRING,
	INTEGER,
	FLOAT,
	DOUBLE
}	t_type;

class	ScalarConverter
{
	public:
		static void	convert(const std::string literal);
	protected:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& scalarConverter);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter(void);
};
