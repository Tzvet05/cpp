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

		void	executeMe(void) const;
	private:
		const std::string	_target;
};
