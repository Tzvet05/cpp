#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("Target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm): AForm("ShrubberyCreationForm", 145, 137), _target(shrubberyCreationForm._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == 0)
		throw(FormUnsignedException());
	else if (executor.getGrade() > this->getExecGrade())
		throw(GradeTooLowException());
	std::ofstream	outfile((_target + "_shrubbery").c_str());
	outfile << "       _-_                 _-_" << std::endl <<
		"    /~~   ~~\\           /~~   ~~\\" << std::endl <<
		" /~~         ~~\\     /~~         ~~\\" << std::endl <<
		"{               }   {               }" << std::endl <<
		" \\  _-     -_  /     \\  _-     -_  /" << std::endl <<
		"   ~  \\\\ //  ~         ~  \\\\ //  ~" << std::endl <<
		"_- -   | | _- _     _- -   | | _- _" << std::endl <<
		"  _ -  | |   -_       _ -  | |   -_" << std::endl <<
		"      // \\\\               // \\\\" << std::endl;
	outfile.close();
}
