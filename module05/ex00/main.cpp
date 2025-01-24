#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	b1;
	try
	{
		b1.decGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;

	Bureaucrat	b2("Stanley", 2);
	try
	{
		b2.incGrade();
		b2.incGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b2 << std::endl;

	try
	{
		Bureaucrat	b3("Terry", 151);
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
