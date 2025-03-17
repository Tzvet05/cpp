#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(const std::string& target);

		void	executeMe(void) const;
	private:
		const std::string	_target;
};
