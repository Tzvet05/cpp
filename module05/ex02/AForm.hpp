#pragma once

#include <exception>

class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm(void);

		AForm(const std::string name, unsigned int signGrade, unsigned int execGrade);

		const std::string&	getName(void) const;
		bool			getSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;

		virtual void	beSigned(Bureaucrat& bureaucrat) = 0;
		virtual void	execute(Bureaucrat const & executor) const;
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
	class	FormUnsignedException: public std::exception
	{
		public:
			FormUnsignedException(void);

			const char*	what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
