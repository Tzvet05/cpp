#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	b1("Stanley", 1), b2("John", 150);
	PresidentialPardonForm	ppf1("Culprit");
	RobotomyRequestForm	rrf1("Subject");
	ShrubberyCreationForm	scf1("Place");

	try
	{
		ppf1.execute(b2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat \"" << b2.getName() << "\" couldn't execute the form \"" << ppf1.getName() << "\" because of the following reason : " << e.what() << std::endl;
	}
	b2.executeForm(ppf1);

	b2.signForm(ppf1);
	b2.signForm(rrf1);
	b2.signForm(scf1);
	b1.signForm(ppf1);
	b1.signForm(rrf1);
	b1.signForm(scf1);
	b2.signForm(ppf1);

	try
	{
		ppf1.execute(b2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat \"" << b2.getName() << "\" couldn't execute the form \"" << ppf1.getName() << "\" because of the following reason : " << e.what() << std::endl;
	}
	try
	{
		ppf1.execute(b1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat \"" << b1.getName() << "\" couldn't execute the form \"" << ppf1.getName() << "\" because of the following reason : " << e.what() << std::endl;
	}
	try
	{
		rrf1.execute(b1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat \"" << b1.getName() << "\" couldn't execute the form \"" << rrf1.getName() << "\" because of the following reason : " << e.what() << std::endl;
	}
	try
	{
		scf1.execute(b1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat \"" << b1.getName() << "\" couldn't execute the form \"" << scf1.getName() << "\" because of the following reason : " << e.what() << std::endl;
	}

	b2.executeForm(ppf1);
	b1.executeForm(ppf1);
	b1.executeForm(rrf1);
	b1.executeForm(scf1);
	return (0);
}
