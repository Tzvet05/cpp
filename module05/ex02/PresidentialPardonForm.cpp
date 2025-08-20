#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm): AForm("PresidentialPardonForm", 25, 5), _target(presidentialPardonForm._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == 0)
		throw(FormUnsignedException());
	else if (executor.getGrade() > this->getExecGrade())
		throw(GradeTooLowException());
	std::cout << "\"" << _target << "\" has been pardoned by Zaphod Beeblebrox" << std::endl;
}
