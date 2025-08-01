#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "BitcoinExchange.hpp"

Date::Date(void)
{
	_year = 0;
	_month = 0;
	_day = 0;
}

Date::Date(const Date& date)
{
	_year = date._year;
	_month = date._month;
	_day = date._day;
}

Date&	Date::operator=(const Date& rhs)
{
	if (this != &rhs)
	{
		_year = rhs._year;
		_month = rhs._month;
		_day = rhs._day;
	}
	return (*this);
}

Date::~Date(void) {}

Date::Date(std::string date)
{
	size_t	len = date.find("-");
	_year = std::strtol(date.substr(0, len).c_str(), NULL, 10);
	len++;
	date.erase(0, len);
	len = date.find("-");
	_month = std::strtol(date.substr(0, len).c_str(), NULL, 10);
	len++;
	date.erase(0, len);
	_day = std::strtol(date.c_str(), NULL, 10);
}

bool	Date::operator<(const Date& rhs) const
{
	return (this->_year < rhs._year || (this->_year == rhs._year && this->_month < rhs._month) || (this->_year == rhs._year && this->_month == rhs._month && this->_day < rhs._day));
}

bool	Date::operator==(const Date& rhs) const
{
	return (_year == rhs._year && _month == rhs._month && _day == rhs._day);
}

Rate::Rate(void)
{
	_date = Date();
	_rate = 0.f;
}

Rate::Rate(const Rate& rate)
{
	_date = rate._date;
	_rate = rate._rate;
}

Rate&	Rate::operator=(const Rate& rhs)
{
	if (this != &rhs)
	{
		_date = rhs._date;
		_rate = rhs._rate;
	}
	return (*this);
}

Rate::~Rate(void) {}

bool	Rate::operator==(const Rate& rhs) const
{
	return (_date == rhs._date);
}

Rate::Rate(Date& date, std::string& str_rate)
{
	_date = date;
	_rate = std::strtof(str_rate.c_str(), NULL);
}

bool	Rate::date_less(const Rate& lhs, const Rate& rhs)
{
	return (lhs.get_date() < rhs.get_date());
}

Date	Rate::get_date(void) const
{
	return (_date);
}

float	Rate::get_rate(void) const
{
	return (_rate);
}

bool	BitcoinExchange::date_is_valid(std::string date)
{
	ssize_t	len = std::min(date.find("-"), date.length());
	if (len == 0 || date.substr(0, len).find_first_not_of("0123456789") != std::string::npos)
		return (false);
	ssize_t	year = std::strtol(date.substr(0, len).c_str(), NULL, 10);
	if (errno == ERANGE)
		return (false);
	if (date[len] == '-')
		len++;
	date.erase(0, len);
	len = std::min(date.find("-"), date.length());
	if (len == 0 || date.substr(0, len).find_first_not_of("0123456789") != std::string::npos)
		return (false);
	ssize_t	month = std::strtol(date.substr(0, len).c_str(), NULL, 10);
	if (errno == ERANGE)
		return (false);
	if (date[len] == '-')
		len++;
	date.erase(0, len);
	len = std::min(date.find("-"), date.length());
	if (len == 0 || date.substr(0, len).find_first_not_of("0123456789") != std::string::npos)
		return (false);
	ssize_t	day = std::strtol(date.substr(0, len).c_str(), NULL, 10);
	if (errno == ERANGE)
		return (false);
	date.erase(0, len);
	if (date.length() > 0)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	static const ssize_t	days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	ssize_t	max_day = days[month - 1];
	if (month == 2 && ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)))
		max_day = 29;
	if (year < 0 || day < 1 || day > max_day)
		return (false);
	return (true);
}

bool	BitcoinExchange::rate_is_valid(std::string rate)
{
	if (rate.length() == 0 || rate.find_first_of("0123456789") == std::string::npos || rate.find_first_not_of("0123456789.-") != std::string::npos)
		return (false);
	std::strtof(rate.c_str(), NULL);
	if (errno == ERANGE)
		return (false);
	return (true);
}

bool	BitcoinExchange::value_is_valid(std::string value)
{
	if (value.length() == 0 || value.find_first_of("0123456789") == std::string::npos || value.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	float	v = std::strtof(value.c_str(), NULL);
	if (errno == ERANGE || v < 0.f || v > 1000.f)
		return (false);
	return (true);
}

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	infile("data.csv");
	if (!infile.is_open())
		throw FileOpeningException();
	std::string line;
	getline(infile, line);
	while (getline(infile, line))
	{
		size_t	len = std::min(line.find(","), line.length());
		std::string	str_date = line.substr(0, len);
		if (!date_is_valid(str_date))
		{
			infile.close();
			throw DateInvalidException();
		}
		if (line[len] == ',')
			len++;
		line.erase(0, len);
		len = std::min(line.find(","), line.length());
		std::string	str_rate = line.substr(0, len);
		if (!rate_is_valid(str_rate))
		{
			infile.close();
			throw RateInvalidException();
		}
		Date	date(str_date);
		Rate	rate(date, str_rate);
		if (std::find(_exchange_rates.begin(), _exchange_rates.end(), rate) != _exchange_rates.end())
		{
			infile.close();
			throw DuplicateKeyException();
		}
		_exchange_rates.push_back(rate);
	}
	infile.close();
	if (_exchange_rates.size() == 0)
		throw EmptyRatesException();
	_exchange_rates.sort(Rate::date_less);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoinExchange)
{
	_exchange_rates = bitcoinExchange._exchange_rates;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		_exchange_rates = rhs._exchange_rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

float	BitcoinExchange::retrieve_rate(Date& date)
{
	std::string	str("0.f");
	Rate	rate(date, str);
	std::list<Rate>::iterator	found = std::find(_exchange_rates.begin(), _exchange_rates.end(), rate);
	if (found == _exchange_rates.end())
	{
		std::list<Rate>::iterator	prev_it = _exchange_rates.begin();
		for (std::list<Rate>::iterator it = _exchange_rates.begin(); it != _exchange_rates.end(); it++)
		{
			if (!(it->get_date() < date))
			{
				found = prev_it;
				break;
			}
			prev_it = it;
		}
		found = prev_it;
	}
	return (found->get_rate());
}

void	BitcoinExchange::calculateValues(std::string infile_name)
{
	std::ifstream	infile(infile_name.c_str());
	if (!infile.is_open())
		throw FileOpeningException();
	std::string line;
	getline(infile, line);
	while (getline(infile, line))
	{
		size_t	len = std::min(line.find(" | "), line.length());
		std::string	str_date = line.substr(0, len);
		if (!date_is_valid(str_date))
		{
			std::cerr << "Error: invalid date: \"" << str_date << "\"" << std::endl;
			continue;
		}
		if (len < line.length())
			len += 3;
		line.erase(0, len);
		len = line.length();
		std::string	str_value = line.substr(0, len);
		if (!value_is_valid(str_value))
		{
			std::cerr << "Error: ";
			if (std::strtof(str_value.c_str(), NULL) < 0.f)
				std::cerr << "non-positive";
			else if (std::strtof(str_value.c_str(), NULL) > 1000.f)
				std::cerr << "too large";
			else
				std::cerr << "invalid";
			std::cerr << " value: \"" << str_value << "\"" << std::endl;
			continue;
		}
		Date	date(str_date);
		float	value = std::strtof(str_value.c_str(), NULL), rate = retrieve_rate(date);
		std::cout << str_date << " : " << value << " * " << rate << " = " << value * rate << std::endl;
	}
}

BitcoinExchange::FileOpeningException::FileOpeningException(void) {}

const char*	BitcoinExchange::FileOpeningException::what(void) const throw()
{
	return ("failed to open file");
}

BitcoinExchange::DateInvalidException::DateInvalidException(void) {}

const char*	BitcoinExchange::DateInvalidException::what(void) const throw()
{
	return ("invalid date");
}

BitcoinExchange::RateInvalidException::RateInvalidException(void) {}

const char*	BitcoinExchange::RateInvalidException::what(void) const throw()
{
	return ("invalid value");
}

BitcoinExchange::DuplicateKeyException::DuplicateKeyException(void) {}

const char*	BitcoinExchange::DuplicateKeyException::what(void) const throw()
{
	return ("key already present in std::list container");
}

BitcoinExchange::EmptyRatesException::EmptyRatesException(void) {}

const char*	BitcoinExchange::EmptyRatesException::what(void) const throw()
{
	return ("no entries in exchange rates database");
}
