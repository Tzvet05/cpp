#include <sstream>
#include <limits>
#include <cstdlib>
#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& rpn): _stack(rpn._stack) {}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return (*this);
}

RPN::~RPN(void) {}

long	RPN::perform_operation(long lhs, std::string& operation, long rhs)
{
	if (operation == "+")
		return (lhs + rhs);
	if (operation == "-")
		return (lhs - rhs);
	if (operation == "*")
		return (lhs * rhs);
	return (lhs / rhs);
}

std::string	RPN::process(std::string expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ')
			continue;

		size_t	len = std::min(expression.find_first_of(" ", i) - i,
				expression.length() - i);
		std::string	token = expression.substr(i, len);

		if (token.find_first_not_of("0123456789") == std::string::npos)
		{
			if (len > 1)
				throw TooManyDigitsException(token);
			_stack.push(static_cast<long>(token[0]) - 48);
		}
		else if (token.find_first_not_of("+-*/") == std::string::npos)
		{
			if (len > 1)
				throw TooManyOperatorsException(token);

			if (_stack.empty())
				throw NotEnoughNumbersException(token);
			long	rhs = _stack.top(), lhs;
			_stack.pop();
			if (_stack.empty())
				throw NotEnoughNumbersException(token);
			lhs = _stack.top();
			_stack.pop();

			if (token == "/" && rhs == 0)
				throw DivisionByZeroException(token);

			_stack.push(perform_operation(lhs, token, rhs));
		}
		else
			throw UnknownTokenException(token);
	}
	if (_stack.empty())
		throw EmptyExpressionException();
	std::stringstream	ss;
	ss << _stack.top();
	if (_stack.size() > 1)
	{
		std::string	error = ss.str();
		throw NotEnoughOperatorsException(error);
	}
	return (ss.str());
}

RPN::TooManyDigitsException::TooManyDigitsException(std::string& error): _error("number has too many digits (must have one only): \"" + error + "\"") {}

RPN::TooManyDigitsException::~TooManyDigitsException(void) throw() {}

const char*	RPN::TooManyDigitsException::what(void) const throw()
{
	return (_error.c_str());
}

RPN::TooManyOperatorsException::TooManyOperatorsException(std::string& error): _error("operator has too many characters (must have one only): \"" + error + "\"") {}

RPN::TooManyOperatorsException::~TooManyOperatorsException(void) throw() {}

const char*	RPN::TooManyOperatorsException::what(void) const throw()
{
	return (_error.c_str());
}

RPN::UnknownTokenException::UnknownTokenException(std::string& error): _error("unknown token (must be exclusively a digit or exclusively an operator ('+', '-', '*' or '/')): \"" + error + "\"") {}

RPN::UnknownTokenException::~UnknownTokenException(void) throw() {}

const char*	RPN::UnknownTokenException::what(void) const throw()
{
	return (_error.c_str());
}

RPN::NotEnoughNumbersException::NotEnoughNumbersException(std::string& error): _error("invalid syntax (operator lacks numbers to operate on): \"" + error + "\"") {}

RPN::NotEnoughNumbersException::~NotEnoughNumbersException(void) throw() {}

const char*	RPN::NotEnoughNumbersException::what(void) const throw()
{
	return (_error.c_str());
}

RPN::DivisionByZeroException::DivisionByZeroException(std::string& error): _error("impossible operation (division by zero): \"" + error + "\"") {}

RPN::DivisionByZeroException::~DivisionByZeroException(void) throw() {}

const char*	RPN::DivisionByZeroException::what(void) const throw()
{
	return (_error.c_str());
}

RPN::NotEnoughOperatorsException::NotEnoughOperatorsException(std::string& error): _error("invalid syntax (too few operators, multiple numbers left): \"" + error + "\"") {}

RPN::NotEnoughOperatorsException::~NotEnoughOperatorsException(void) throw() {}

const char*	RPN::NotEnoughOperatorsException::what(void) const throw()
{
	return (_error.c_str());
}

RPN::EmptyExpressionException::EmptyExpressionException(void): _error("empty expression provided (must contain valid numbers and operators)") {}

RPN::EmptyExpressionException::~EmptyExpressionException(void) throw() {}

const char*	RPN::EmptyExpressionException::what(void) const throw()
{
	return (_error.c_str());
}
