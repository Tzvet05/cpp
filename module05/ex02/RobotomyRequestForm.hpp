#pragma once

#include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const std::string& target);

		void	execute(Bureaucrat const & executor) const;
	private:
		const std::string	_target;
};
