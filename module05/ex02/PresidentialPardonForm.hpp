#pragma once

class	AForm;

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(const std::string& target);
	private:
		const std::string	_target;
};
