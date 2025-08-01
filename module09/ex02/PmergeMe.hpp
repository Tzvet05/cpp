#include <stddef.h>
#include <string>
#include <exception>
#include <vector>
#include <deque>

enum	Partition
{
	MAIN,
	PEND
};

class	PmergeMeVector
{
	public:
		PmergeMeVector(void);
		PmergeMeVector(const PmergeMeVector& pmergemevector);
		PmergeMeVector& operator=(const PmergeMeVector& rhs);
		~PmergeMeVector(void);

		PmergeMeVector(char** arr);

		std::vector<int>	get_vector(void) const;
		size_t			get_duration(void) const;

		void		sort(void);
		std::string	print(void);

	private:
		size_t	binary_search(std::vector<int>& main,
				size_t i_end, int v, size_t len_elem) const;

		std::vector<int>	_vector;
		size_t			_duration;

		class	NotANumberException: public std::exception
		{
			public:
				NotANumberException(std::string& error);
				~NotANumberException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	NumberTooLargeException: public std::exception
		{
			public:
				NumberTooLargeException(std::string& error);
				~NumberTooLargeException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	NegativeNumberException: public std::exception
		{
			public:
				NegativeNumberException(std::string& error);
				~NegativeNumberException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
};

class	PmergeMeDeque
{
	public:
		PmergeMeDeque(void);
		PmergeMeDeque(const PmergeMeDeque& pmergemedeque);
		PmergeMeDeque& operator=(const PmergeMeDeque& rhs);
		~PmergeMeDeque(void);

		PmergeMeDeque(char** arr);

		std::deque<int>	get_deque(void) const;
		size_t		get_duration(void) const;

		void		sort(void);
		std::string	print(void);

	private:
		size_t	binary_search(std::deque<int>& main,
				size_t i_end, int v, size_t len_elem) const;

		std::deque<int>	_deque;
		size_t		_duration;

		class	NotANumberException: public std::exception
		{
			public:
				NotANumberException(std::string& error);
				~NotANumberException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	NumberTooLargeException: public std::exception
		{
			public:
				NumberTooLargeException(std::string& error);
				~NumberTooLargeException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
		class	NegativeNumberException: public std::exception
		{
			public:
				NegativeNumberException(std::string& error);
				~NegativeNumberException(void) throw();

				const char*	what(void) const throw();

			private:
				const std::string	_error;
		};
};
