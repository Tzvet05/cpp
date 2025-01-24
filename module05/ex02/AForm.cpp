#include <iostream>
#include "AAForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("AForm"), _signGrade(150), _execGrade(150)
{
	_signed = 0;
}

AForm::AForm(const AForm& form): _name(form._name), _signGrade(form._signGrade), _execGrade(form._execGrade)
{
	_signed = form._signed;
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

AForm::~AForm(void)
{
}

AForm::AForm(const std::string name, unsigned int signGrade, unsigned int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw (GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (GradeTooLowException());
	_signed = 0;
}


const std::string&	AForm::getName(void) const
{
	return (_name);
}

bool			AForm::getSigned(void) const
{
	return (_signed);
}

unsigned int		AForm::getSignGrade(void) const
{
	return (_signGrade);
}

unsigned int		AForm::getExecGrade(void) const
{
	return (_execGrade);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw (GradeTooLowException());
	_signed = 1;
}

void	execute(Bureaucrat const & executor) const
{
	if (_signed == 0)
		throw(FormUnsignedException());
	else if (executor.getGrade() > _execGrade)
		throw(GradeTooLowException());
	;// execute the form -> add new function to override in every child ? but will parent AForm know to call the overriden version ?
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	std::string	sign_state;

	if (form.getSigned() == 1)
		sign_state = "signed";
	else
		sign_state = "not signed";
	os << "AForm \"" << form.getName() << "\" is " << sign_state << " and has a minimum signing grade of " << form.getSignGrade() << " and a minimum execution grade of " << form.getExecGrade();
	return (os);
}

AForm::GradeTooHighException::GradeTooHighException(void)
{
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

AForm::GradeTooLowException::GradeTooLowException(void)
{
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

AForm::FormUnsignedException::FormUnsignedException(void)
{
}

const char*	AForm::FormUnsignedException::what(void) const throw()
{
	return ("Form isn't signed");
}
