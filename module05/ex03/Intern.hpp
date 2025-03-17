#pragma once

class	AForm;

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern& intern);
		Intern& operator=(const Intern&);
		~Intern(void);

		AForm*	makeForm(const std::string name, const std::string target) const;
};
