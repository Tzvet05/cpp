#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("Target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm): AForm("RobotomyRequestForm", 72, 45), _target(robotomyRequestForm._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == 0)
		throw(FormUnsignedException());
	else if (executor.getGrade() > this->getExecGrade())
		throw(GradeTooLowException());
	srand(time(NULL));
	std::cout << "* vrrrr *" << std::endl << "* vrrrr *" << std::endl << "* vrrrr *" << std::endl;
	if ((rand() % 2) == 1)
		std::cout << "\"" << _target << "\" has been successfully robotomized" << std::endl;
	else
		std::cout << "The robotomy attempt on \"" << _target << "\" failed" << std::endl;
}
