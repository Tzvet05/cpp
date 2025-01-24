#pragma once

#include <exception>

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat(void);

		Bureaucrat(const std::string name, unsigned int grade);

		const std::string&	getName(void) const;
		unsigned int		getGrade(void) const;

		void	incGrade(void);
		void	decGrade(void);
		void	signForm(Form& form);
	private:
		const std::string	_name;
		unsigned int		_grade;

	class	GradeTooHighException: public std::exception
	{
		public:
			GradeTooHighException(void);

			const char*	what(void) const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		public:
			GradeTooLowException(void);

			const char*	what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
