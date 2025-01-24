#ifndef __FIXED_H__
#define __FIXED_H__

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed&);
		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int			_value;
		static const int	_fractBits = 8;
};

#endif
