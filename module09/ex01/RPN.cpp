#include <sstream>
#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& rpn)
{
	_expression = rpn._expression;
}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
		_expression = rhs._expression;
	return (*this);
}

RPN::~RPN(void) {}

RPN::RPN(std::string expression)
{
	expression.erase(0, std::min(expression.find_first_not_of(" "), expression.length()));
	expression.erase(std::min<long>(expression.find_last_not_of(" ") + 1,
		std::max<long>(expression.length() - 1, 0)),
		expression.length() - std::min<long>(expression.find_last_not_of(" ") + 1,
		expression.length()));
	size_t	i_elem;
	std::string	element;
	while (!expression.empty())
	{
		if (expression.find(" ") != std::string::npos)
			i_elem = expression.find_last_of(" ") + 1;
		else
			i_elem = 0;
		element = expression.substr(i_elem, expression.length() - i_elem);
		expression.erase(i_elem, element.length());
		expression.erase(std::min<long>(expression.find_last_not_of(" ") + 1,
			std::max<long>(expression.length() - 1, 0)),
			expression.length() - std::min<long>(expression.find_last_not_of(" ") + 1,
			expression.length()));
		if (element.find_first_not_of("0123456789") == std::string::npos
			&& element.length() > 1)
			throw TooManyDigitsException(element);
		if (element.length() > 1
			|| element.find_first_of("0123456789+-*/") == std::string::npos)
			throw UnknownTokenException(element);
		_expression.push(element);
	}
}

long	RPN::perform_operation(long a, std::string& operation, long b)
{
	if (operation == "+")
		return (a + b);
	if (operation == "-")
		return (a - b);
	if (operation == "*")
		return (a * b);
	return (a / b);
}

std::string	RPN::process(void)
{
	if (_expression.size() < 3 || (_expression.size() & 1) == 0)
		return ("0");
	std::string	number = _expression.top(), operation;
	_expression.pop();
	if (number.find_first_not_of("0123456789") != std::string::npos)
		return ("0");
	long	result = (long)number[0] - 48;
	while (!_expression.empty())
	{
		number = _expression.top();
		_expression.pop();
		operation = _expression.top();
		_expression.pop();
		if (number.find_first_not_of("0123456789") != std::string::npos
			|| operation.find_first_not_of("+-*/") != std::string::npos
			|| (number == "0" && operation == "/"))
			return ("0");
		result = perform_operation(result, operation, (long)number[0] - 48);
	}
	std::stringstream	ss;
	ss << result;
	return (ss.str());
}

RPN::TooManyDigitsException::TooManyDigitsException(std::string& error): _error("number has too many digits (must have only one): \"" + error + "\"") {}

RPN::TooManyDigitsException::~TooManyDigitsException(void) throw() {}

const char*	RPN::TooManyDigitsException::what(void) const throw()
{
	return (_error.c_str());
}

RPN::UnknownTokenException::UnknownTokenException(std::string& error): _error("unknown token (must be a digit or one of '+', '-', '*', '/'): \"" + error + "\"") {}

RPN::UnknownTokenException::~UnknownTokenException(void) throw() {}

const char*	RPN::UnknownTokenException::what(void) const throw()
{
	return (_error.c_str());
}
