#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("Bureaucrat")
{
	_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat): _name(bureaucrat._name)
{
	_grade = bureaucrat._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incGrade(void)
{
	if (_grade <= 1)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decGrade(void)
{
	if (_grade >= 150)
		throw (GradeTooLowException());
	_grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat \"" << _name << "\" couldn't sign the form \"" << form.getName() << "\" because of the following reason : " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat \"" << _name << "\" signed the form \"" << form.getName() << "\"" << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << "Bureaucrat \"" << _name << "\" couldn't execute the form \"" << form.getName() << "\" because of the following reason : " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat \"" << _name << "\" executed the form \"" << form.getName() << "\"" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high (grade must be >= 1)");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low (grade must be <= 150)");
}
