#pragma once

class	AForm;

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(const std::string& target);
	private:
		const std::string	_target;
};
