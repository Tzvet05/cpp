#pragma once

#include <vector>
#include <algorithm>
#include <functional>

class	Span
{
	public:
		Span(void);
		Span(const Span& span);
		Span& operator=(const Span& rhs);
		~Span(void);

		Span(unsigned int N);

		void	addNumber(int n);
		template <typename T>
		void	addNumbersRange(T begin, T end)
		{
			for (T it = begin; it != end; it++)
			{
				if (_numbers.size() >= _size)
					throw MaximumElementsException();
				_numbers.push_back(*it);
			}
		}
		size_t	shortestSpan(void);
		size_t	longestSpan(void);

	private:
		size_t			_size;
		std::vector<int>	_numbers;

		class	MaximumElementsException: public std::exception
		{
			public:
				MaximumElementsException(void);

				const char*	what(void) const throw();
		};
		class	InsufficientElementsException: public std::exception
		{
			public:
				InsufficientElementsException(void);

				const char*	what(void) const throw();
		};
};
