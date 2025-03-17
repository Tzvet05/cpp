#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern&)
{
}

Intern& Intern::operator=(const Intern&)
{
	return (*this);
}

Intern::~Intern(void)
{
}

AForm*	Intern::makeForm(const std::string name, const std::string target) const
{
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	size_t	i = 0;
	while (i < 3)
	{
		size_t	i_char = 0;
		while (forms[i][i_char] != '\0' && forms[i][i_char] == std::tolower(name[i_char]))
			i_char++;
		if (forms[i][i_char] == std::tolower(name[i_char]))
			break;
		i++;
	}
	switch (i)
	{
		case (0):
		{
			std::cout << "Intern created a Presidential Pardon form" << std::endl;
			return (new PresidentialPardonForm(target));
		}
		case (1):
		{
			std::cout << "Intern created a Robotomy Request form" << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case (2):
		{
			std::cout << "Intern created a Shrubbery Creation form" << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		default:
		{
			std::cerr << "Intern couldn't create a form of type \"" << name << "\" because this type doesn't exist" << std::endl;
			return (NULL);
		}
	}
}
