#pragma once

#include <exception>

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form(void);

		Form(const std::string name, unsigned int signGrade, unsigned int execGrade);

		const std::string&	getName(void) const;
		bool			getSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;

		void	beSigned(Bureaucrat& bureaucrat);
	private:
		const std::string	_name;
		bool			_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

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

std::ostream& operator<<(std::ostream& os, const Form& form);
