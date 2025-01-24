#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed&);
		~Fixed(void);

		Fixed(const int value);
		Fixed(const float value);

		float	toFloat(void) const;
		int	toInt(void) const;

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		bool	operator>(const Fixed& fixed) const;
		bool	operator<(const Fixed& fixed) const;
		bool	operator>=(const Fixed& fixed) const;
		bool	operator<=(const Fixed& fixed) const;
		bool	operator==(const Fixed& fixed) const;
		bool	operator!=(const Fixed& fixed) const;

		Fixed	operator+(const Fixed& fixed);
		Fixed	operator-(const Fixed& fixed);
		Fixed	operator*(const Fixed& fixed);
		Fixed	operator/(const Fixed& fixed);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&	max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);
	private:
		int			_value;
		static const int	_fractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
