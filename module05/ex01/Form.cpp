#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Form"), _signGrade(150), _execGrade(150)
{
	_signed = 0;
}

Form::Form(const Form& form): _name(form._name), _signGrade(form._signGrade), _execGrade(form._execGrade)
{
	_signed = form._signed;
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

Form::~Form(void)
{
}

Form::Form(const std::string name, unsigned int signGrade, unsigned int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw (GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (GradeTooLowException());
	_signed = 0;
}


const std::string&	Form::getName(void) const
{
	return (_name);
}

bool			Form::getSigned(void) const
{
	return (_signed);
}

unsigned int		Form::getSignGrade(void) const
{
	return (_signGrade);
}

unsigned int		Form::getExecGrade(void) const
{
	return (_execGrade);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw (GradeTooLowException());
	_signed = 1;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	std::string	sign_state;

	if (form.getSigned() == 1)
		sign_state = "signed";
	else
		sign_state = "not signed";
	os << "Form \"" << form.getName() << "\" is " << sign_state << " and has a minimum signing grade of " << form.getSignGrade() << " and a minimum execution grade of " << form.getExecGrade();
	return (os);
}

Form::GradeTooHighException::GradeTooHighException(void)
{
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

Form::GradeTooLowException::GradeTooLowException(void)
{
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}
