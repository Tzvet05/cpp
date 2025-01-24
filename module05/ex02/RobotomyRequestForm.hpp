#pragma once

class	AForm;

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const std::string& target);
	private:
		const std::string	_target;
}
