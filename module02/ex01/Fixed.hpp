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
	private:
		int			_value;
		static const int	_fractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
