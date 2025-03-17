#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	b1("Stanley", 1);
	Intern	i1;
	AForm*	form;

	form = i1.makeForm("none", "target1");
	form = i1.makeForm("Presidential Pardon", "target2");
	std::cout << *form << std::endl;
	b1.signForm(*form);
	b1.executeForm(*form);
	delete form;
	form = i1.makeForm("robotomy request", "target3");
	std::cout << *form << std::endl;
	delete form;
	form = i1.makeForm("SHRUBBERY CREATION", "target4");
	std::cout << *form << std::endl;
	delete form;
	return (0);
}
