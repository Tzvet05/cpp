#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	b1("Stanley", 3);
	Form		f1("Pass A38", 2, 1);
	try
	{
		f1.beSigned(b1);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "f1: _signed = " << f1.getSigned() << std::endl;

	try
	{
		b1.incGrade();
		f1.beSigned(b1);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "f1: _signed = " << f1.getSigned() << std::endl;

	Form	f2("Form 10-99-10", 2, 2);
	try
	{
		b1.signForm(f2);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "f2: _signed = " << f2.getSigned() << std::endl;

	std::cout << b1 << std::endl;
	Form	f3("Geneva Convention", 1, 1);
	try
	{
		b1.signForm(f3);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "f3: _signed = " << f3.getSigned() << std::endl;
	return (0);
}
