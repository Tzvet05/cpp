#include "Span.hpp"

Span::Span(void)
{
	_size = 0;
}

Span::Span(const Span& span)
{
	_size = span._size;
	_numbers = span._numbers;
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_size = rhs._size;
		_numbers = rhs._numbers;
	}
	return (*this);
}

Span::~Span(void) {}

Span::Span(unsigned int N)
{
	_size = (size_t)N;
}

void	Span::addNumber(int n)
{
	if (_numbers.size() >= _size)
		throw MaximumElementsException();
	_numbers.push_back(n);
}

size_t	Span::shortestSpan(void)
{
	if (_numbers.size() <= 1)
		throw InsufficientElementsException();
	std::sort(_numbers.begin(), _numbers.end(), std::less<int>());
	size_t	span = _numbers.back() - _numbers.front();
	for (std::vector<int>::iterator it = _numbers.begin(); it + 1 != _numbers.end(); it++)
		if ((size_t)(*(it + 1) - *it) < span)
			span = *(it + 1) - *it;
	return (span);
}

size_t	Span::longestSpan(void)
{
	if (_numbers.size() <= 1)
		throw InsufficientElementsException();
	std::sort(_numbers.begin(), _numbers.end(), std::less<int>());
	return (_numbers.back() - _numbers.front());
}

Span::MaximumElementsException::MaximumElementsException(void) {}

const char*	Span::MaximumElementsException::what(void) const throw()
{
	return ("Exceeds maximum number of elements in span object");
}

Span::InsufficientElementsException::InsufficientElementsException(void) {}

const char*	Span::InsufficientElementsException::what(void) const throw()
{
	return ("Insufficient number of elements to search for a span (must be > 1)");
}
