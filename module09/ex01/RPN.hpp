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

		std::string	process(std::string expression);

	private:
		long	perform_operation(long lhs, std::string& operation, long rhs);

		std::stack<long>	_stack;

		class	TooManyDigitsException: public std::exception
		{
			public:
				TooManyDigitsException(std::string& error);
				~TooManyDigitsException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	TooManyOperatorsException: public std::exception
		{
			public:
				TooManyOperatorsException(std::string& error);
				~TooManyOperatorsException(void) throw();

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
		class	NotEnoughNumbersException: public std::exception
		{
			public:
				NotEnoughNumbersException(std::string& error);
				~NotEnoughNumbersException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	DivisionByZeroException: public std::exception
		{
			public:
				DivisionByZeroException(std::string& error);
				~DivisionByZeroException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	NotEnoughOperatorsException: public std::exception
		{
			public:
				NotEnoughOperatorsException(std::string& error);
				~NotEnoughOperatorsException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	EmptyExpressionException: public std::exception
		{
			public:
				EmptyExpressionException(void);
				~EmptyExpressionException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
};
