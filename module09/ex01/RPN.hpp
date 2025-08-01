#pragma once

#include <string>
#include <exception>
#include <stack>

class	RPN
{
	public:
		RPN(void);
		RPN(const RPN& rpn);
		RPN& operator=(const RPN& rhs);
		~RPN(void);

		RPN(std::string expression);

		std::string	process(void);

	private:
		long	perform_operation(long a, std::string& operation, long b);

		std::stack<std::string>	_expression;

		class	TooManyDigitsException: public std::exception
		{
			public:
				TooManyDigitsException(std::string& error);
				~TooManyDigitsException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	UnknownTokenException: public std::exception
		{
			public:
				UnknownTokenException(std::string& error);
				~UnknownTokenException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
};
