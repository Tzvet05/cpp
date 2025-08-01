#pragma once

#include <exception>
#include <fstream>
#include <string>
#include <list>

class	Date
{
	public:
		Date(void);
		Date(const Date& date);
		Date& operator=(const Date& rhs);
		~Date(void);

		Date(std::string date);
		bool	operator<(const Date& rhs) const;
		bool	operator==(const Date& rhs) const;

	private:
		size_t	_year;
		size_t	_month;
		size_t	_day;
};

class	Rate
{
	public:
		Rate(void);
		Rate(const Rate& rate);
		Rate& operator=(const Rate& rhs);
		~Rate(void);

		Rate(Date& date, std::string& str_rate);
		bool	operator==(const Rate& rhs) const;

		static bool	date_less(const Rate& lhs, const Rate& rhs);

		Date	get_date(void) const;
		float	get_rate(void) const;

	private:
		Date	_date;
		float	_rate;
};

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& bitcoinExchange);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange(void);

		bool	date_is_valid(std::string date);
		bool	rate_is_valid(std::string rate);
		bool	value_is_valid(std::string value);
		float	retrieve_rate(Date& date);
		void	calculateValues(std::string infile_name);

	private:
		std::list<Rate>	_exchange_rates;


		class	FileOpeningException: public std::exception
		{
			public:
				FileOpeningException(void);

				const char*	what(void) const throw();
		};
		class	DateInvalidException: public std::exception
		{
			public:
				DateInvalidException(void);

				const char*	what(void) const throw();
		};
		class	RateInvalidException: public std::exception
		{
			public:
				RateInvalidException(void);

				const char*	what(void) const throw();
		};
		class	DuplicateKeyException: public std::exception
		{
			public:
				DuplicateKeyException(void);

				const char*	what(void) const throw();
		};
		class	EmptyRatesException: public std::exception
		{
			public:
				EmptyRatesException(void);

				const char*	what(void) const throw();
		};
};
