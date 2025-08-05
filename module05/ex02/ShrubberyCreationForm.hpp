#pragma once

#include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(const std::string& target);

		void	execute(Bureaucrat const & executor) const;
	private:
		const std::string	_target;
};
