#pragma once

#include <exception>

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat(void);

		Bureaucrat(const std::string name, short grade);

		const std::string&	getName(void) const;
		short			getGrade(void) const;

		void	incGrade(void);
		void	decGrade(void);
	private:
		const std::string	_name;
		short			_grade;
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
