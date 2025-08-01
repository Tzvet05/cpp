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

		Span(unsigned int n);

		void	addNumber(int n);
		template <typename T>
		void	addNumbersRange(T begin, T end)
		{
			size_t	len_range = 0;
			T	it;
			for (it = begin; it != end; it++)
				len_range++;
			if (_numbers.size() + len_range >= _size)
				throw MaximumElementsException();
			for (it = begin; it != end; it++)
				_numbers.push_back(*it);
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
