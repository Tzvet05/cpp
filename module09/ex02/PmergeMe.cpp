#include <limits>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cerrno>
#include "PmergeMe.hpp"

////////// Vector

PmergeMeVector::PmergeMeVector(void): _duration(0) {}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& pmergemevector): _vector(pmergemevector._vector), _duration(pmergemevector._duration) {}

PmergeMeVector&	PmergeMeVector::operator=(const PmergeMeVector& rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_duration = rhs._duration;
	}
	return (*this);
}

PmergeMeVector::~PmergeMeVector(void) {}

PmergeMeVector::PmergeMeVector(char** arr): _duration(0)
{
	std::clock_t	clock_start = std::clock();
	std::string	str_nbr;
	long	nbr;
	size_t	i_arr = 0, i_nbr;
	while (arr[i_arr] != NULL)
	{
		str_nbr = std::string(arr[i_arr]);
		i_nbr = 0;

		if (str_nbr[i_nbr] == '+')
			i_nbr++;
		else if (str_nbr[i_nbr] == '-')
			throw NegativeNumberException(str_nbr);
		if (!std::isdigit(str_nbr[i_nbr]))
			throw NotANumberException(str_nbr);
		while (std::isdigit(str_nbr[i_nbr]))
			i_nbr++;
		if (str_nbr[i_nbr] != '\0')
			throw NotANumberException(str_nbr);

		nbr = std::strtol(str_nbr.c_str(), NULL, 10);
		if (errno == ERANGE || nbr > std::numeric_limits<int>::max())
			throw NumberTooLargeException(str_nbr);
		_vector.push_back(static_cast<int>(nbr));
		i_arr++;
	}
	std::clock_t	clock_end = std::clock();
	_duration += (clock_end - clock_start);
}

std::vector<int>	PmergeMeVector::get_vector(void) const
{
	return (_vector);
}

size_t	PmergeMeVector::get_duration(void) const
{
	return (_duration);
}

size_t	PmergeMeVector::binary_search(std::vector<int>& main,
		size_t i_end, int v, size_t len_elem) const
{
	size_t	i_start = 0;
	while (i_end - i_start > 0)
	{
		size_t	i_middle = i_start + (i_end - i_start) / 2;
		if (v > main[(i_middle + 1) * len_elem - 1])
			i_start = i_middle + 1;
		else
			i_end = i_middle;
	}
	return (i_start);
}

void	PmergeMeVector::sort(void)
{
	std::clock_t	clock_start = std::clock();
	size_t	len_elem = 1;
	while (2 * len_elem <= _vector.size())
	{
		size_t	i_elem = 0;
		while (i_elem + 2 * len_elem <= _vector.size())
		{
			if (_vector[i_elem + len_elem - 1] > _vector[i_elem + 2 * len_elem - 1])
			{
				size_t	i_nbr = 0;
				while (i_nbr < len_elem)
				{
					int	tmp = _vector[i_elem + i_nbr];
					_vector[i_elem + i_nbr]
						= _vector[i_elem + len_elem + i_nbr];
					_vector[i_elem + len_elem + i_nbr] = tmp;
					i_nbr++;
				}
			}
			i_elem += 2 * len_elem;
		}
		len_elem *= 2;
	}
	len_elem /= 2;

	while (len_elem >= 1)
	{
		std::vector<int>	winners, losers;
		winners.insert(winners.begin(), _vector.begin(), _vector.begin() + len_elem);
		enum Partition	part = WINNERS;
		size_t	i_elem = len_elem;
		while (i_elem + len_elem <= _vector.size())
		{
			if (part == WINNERS)
			{
				winners.insert(winners.end(), _vector.begin() + i_elem,
					_vector.begin() + i_elem + len_elem);
				part = LOSERS;
			}
			else
			{
				losers.insert(losers.end(), _vector.begin() + i_elem,
					_vector.begin() + i_elem + len_elem);
				part = WINNERS;
			}
			i_elem += len_elem;
		}
		_vector.erase(_vector.begin(), _vector.begin() + i_elem);

		size_t	curr_jacobshtal = 3, prev_jacobsthal = 1, tmp_jacobsthal,
			diff_jacobsthal, i_jacobsthal, n_inserted = 0;
		while (n_inserted < losers.size() / len_elem)
		{
			diff_jacobsthal = std::min(curr_jacobshtal - prev_jacobsthal,
				(losers.size() / len_elem) - n_inserted);
			i_jacobsthal = 0;
			while (i_jacobsthal < diff_jacobsthal)
			{
				int	v_cmp = losers[(prev_jacobsthal
					+ (diff_jacobsthal - i_jacobsthal) - 1) * len_elem - 1];
				size_t	i_insert = binary_search(winners, std::min(prev_jacobsthal
					+ (diff_jacobsthal - i_jacobsthal) + n_inserted,
					winners.size() / len_elem), v_cmp, len_elem);
				winners.insert(winners.begin() + (i_insert * len_elem), losers.begin()
					+ (prev_jacobsthal + (diff_jacobsthal - i_jacobsthal) - 2)
					* len_elem, losers.begin() + (prev_jacobsthal
					+ (diff_jacobsthal - i_jacobsthal) - 1) * len_elem);
				i_jacobsthal++;
				n_inserted++;
			}
			tmp_jacobsthal = prev_jacobsthal;
			prev_jacobsthal = curr_jacobshtal;
			curr_jacobshtal += 2 * tmp_jacobsthal;
		}

		_vector.insert(_vector.begin(), winners.begin(), winners.end());
		len_elem /= 2;
	}
	std::clock_t	clock_end = std::clock();
	_duration += (clock_end - clock_start);
}

std::string	PmergeMeVector::print(void) const
{
	std::stringstream	ss;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		ss << *it;
		if (it + 1 != _vector.end())
			ss << " ";
	}
	return (ss.str());
}

PmergeMeVector::NotANumberException::NotANumberException(std::string& error): _error("argument is not a number (must be a number composed of digits, possibly preceded by a single sign ('+' or '-')): \"" + error + "\"") {}

PmergeMeVector::NotANumberException::~NotANumberException(void) throw() {}

const char*	PmergeMeVector::NotANumberException::what(void) const throw()
{
	return (_error.c_str());
}

PmergeMeVector::NumberTooLargeException::NumberTooLargeException(std::string& error): _error("number is too large (must fit inside an int32_t): \"" + error + "\"") {}

PmergeMeVector::NumberTooLargeException::~NumberTooLargeException(void) throw() {}

const char*	PmergeMeVector::NumberTooLargeException::what(void) const throw()
{
	return (_error.c_str());
}

PmergeMeVector::NegativeNumberException::NegativeNumberException(std::string& error): _error("number is negative (must be >= 0): \"" + error + "\"") {}

PmergeMeVector::NegativeNumberException::~NegativeNumberException(void) throw() {}

const char*	PmergeMeVector::NegativeNumberException::what(void) const throw()
{
	return (_error.c_str());
}

////////// Deque

PmergeMeDeque::PmergeMeDeque(void): _duration(0) {}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& pmergemedeque): _deque(pmergemedeque._deque), _duration(pmergemedeque._duration) {}

PmergeMeDeque&	PmergeMeDeque::operator=(const PmergeMeDeque& rhs)
{
	if (this != &rhs)
	{
		_deque = rhs._deque;
		_duration = rhs._duration;
	}
	return (*this);
}

PmergeMeDeque::~PmergeMeDeque(void) {}

PmergeMeDeque::PmergeMeDeque(char** arr): _duration(0)
{
	std::clock_t	clock_start = std::clock();
	std::string	str_nbr;
	long	nbr;
	size_t	i_arr = 0, i_nbr;
	while (arr[i_arr] != NULL)
	{
		str_nbr = std::string(arr[i_arr]);
		i_nbr = 0;

		if (str_nbr[i_nbr] == '+')
			i_nbr++;
		else if (str_nbr[i_nbr] == '-')
			throw NegativeNumberException(str_nbr);
		if (!std::isdigit(str_nbr[i_nbr]))
			throw NotANumberException(str_nbr);
		while (std::isdigit(str_nbr[i_nbr]))
			i_nbr++;
		if (str_nbr[i_nbr] != '\0')
			throw NotANumberException(str_nbr);

		nbr = std::strtol(str_nbr.c_str(), NULL, 10);
		if (errno == ERANGE || nbr > std::numeric_limits<int>::max())
			throw NumberTooLargeException(str_nbr);
		_deque.push_back(static_cast<int>(nbr));
		i_arr++;
	}
	std::clock_t	clock_end = std::clock();
	_duration += (clock_end - clock_start);
}

std::deque<int>	PmergeMeDeque::get_deque(void) const
{
	return (_deque);
}

size_t	PmergeMeDeque::get_duration(void) const
{
	return (_duration);
}

size_t	PmergeMeDeque::binary_search(std::deque<int>& main,
		size_t i_end, int v, size_t len_elem) const
{
	size_t	i_start = 0;
	while (i_end - i_start > 0)
	{
		size_t	i_middle = i_start + (i_end - i_start) / 2;
		if (v > main[(i_middle + 1) * len_elem - 1])
			i_start = i_middle + 1;
		else
			i_end = i_middle;
	}
	return (i_start);
}

void	PmergeMeDeque::sort(void)
{
	std::clock_t	clock_start = std::clock();
	size_t	len_elem = 1;
	while (2 * len_elem <= _deque.size())
	{
		size_t	i_elem = 0;
		while (i_elem + 2 * len_elem <= _deque.size())
		{
			if (_deque[i_elem + len_elem - 1] > _deque[i_elem + 2 * len_elem - 1])
			{
				size_t	i_nbr = 0;
				while (i_nbr < len_elem)
				{
					int	tmp = _deque[i_elem + i_nbr];
					_deque[i_elem + i_nbr]
						= _deque[i_elem + len_elem + i_nbr];
					_deque[i_elem + len_elem + i_nbr] = tmp;
					i_nbr++;
				}
			}
			i_elem += 2 * len_elem;
		}
		len_elem *= 2;
	}
	len_elem /= 2;

	while (len_elem >= 1)
	{
		std::deque<int>	winners, losers;
		winners.insert(winners.begin(), _deque.begin(), _deque.begin() + len_elem);
		enum Partition	part = WINNERS;
		size_t	i_elem = len_elem;
		while (i_elem + len_elem <= _deque.size())
		{
			if (part == WINNERS)
			{
				winners.insert(winners.end(), _deque.begin() + i_elem,
					_deque.begin() + i_elem + len_elem);
				part = LOSERS;
			}
			else
			{
				losers.insert(losers.end(), _deque.begin() + i_elem,
					_deque.begin() + i_elem + len_elem);
				part = WINNERS;
			}
			i_elem += len_elem;
		}
		_deque.erase(_deque.begin(), _deque.begin() + i_elem);

		size_t	curr_jacobshtal = 3, prev_jacobsthal = 1, tmp_jacobsthal,
			diff_jacobsthal, i_jacobsthal, n_inserted = 0;
		while (n_inserted < losers.size() / len_elem)
		{
			diff_jacobsthal = std::min(curr_jacobshtal - prev_jacobsthal,
				(losers.size() / len_elem) - n_inserted);
			i_jacobsthal = 0;
			while (i_jacobsthal < diff_jacobsthal)
			{
				int	v_cmp = losers[(prev_jacobsthal
					+ (diff_jacobsthal - i_jacobsthal) - 1) * len_elem - 1];
				size_t	i_insert = binary_search(winners, std::min(prev_jacobsthal
					+ (diff_jacobsthal - i_jacobsthal) + n_inserted,
					winners.size() / len_elem), v_cmp, len_elem);
				winners.insert(winners.begin() + (i_insert * len_elem), losers.begin()
					+ (prev_jacobsthal + (diff_jacobsthal - i_jacobsthal) - 2)
					* len_elem, losers.begin() + (prev_jacobsthal
					+ (diff_jacobsthal - i_jacobsthal) - 1) * len_elem);
				i_jacobsthal++;
				n_inserted++;
			}
			tmp_jacobsthal = prev_jacobsthal;
			prev_jacobsthal = curr_jacobshtal;
			curr_jacobshtal += 2 * tmp_jacobsthal;
		}

		_deque.insert(_deque.begin(), winners.begin(), winners.end());
		len_elem /= 2;
	}
	std::clock_t	clock_end = std::clock();
	_duration += (clock_end - clock_start);
}

std::string	PmergeMeDeque::print(void) const
{
	std::stringstream	ss;
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		ss << *it;
		if (it + 1 != _deque.end())
			ss << " ";
	}
	return (ss.str());
}

PmergeMeDeque::NotANumberException::NotANumberException(std::string& error): _error("argument is not a number (must be a number composed of digits, possibly preceded by a single sign ('+' or '-')): \"" + error + "\"") {}

PmergeMeDeque::NotANumberException::~NotANumberException(void) throw() {}

const char*	PmergeMeDeque::NotANumberException::what(void) const throw()
{
	return (_error.c_str());
}

PmergeMeDeque::NumberTooLargeException::NumberTooLargeException(std::string& error): _error("number is too large (must fit inside an int32_t): \"" + error + "\"") {}

PmergeMeDeque::NumberTooLargeException::~NumberTooLargeException(void) throw() {}

const char*	PmergeMeDeque::NumberTooLargeException::what(void) const throw()
{
	return (_error.c_str());
}

PmergeMeDeque::NegativeNumberException::NegativeNumberException(std::string& error): _error("number is negative (must be >= 0): \"" + error + "\"") {}

PmergeMeDeque::NegativeNumberException::~NegativeNumberException(void) throw() {}

const char*	PmergeMeDeque::NegativeNumberException::what(void) const throw()
{
	return (_error.c_str());
}
