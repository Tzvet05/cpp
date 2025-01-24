#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	_value = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		_value = rhs.getRawBits();
	return (*this);
}

Fixed& Fixed::operator=(const int value)
{
	_value = value << _fractBits;
	return (*this);
}

Fixed& Fixed::operator=(const float value)
{
	_value = (int)(value * (float)(1 << _fractBits));
	return (*this);
}

Fixed::Fixed(const int value)
{
	_value = value << _fractBits;
}

Fixed::Fixed(const float value)
{
	_value = (int)(value * (float)(1 << _fractBits));
}

Fixed::~Fixed(void)
{
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fractBits));
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+(const Fixed& fixed)
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& fixed)
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& fixed)
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed&	Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	return (Fixed(++(*this)));
}

Fixed&	Fixed::operator--()
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	return (Fixed(--(*this)));
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	else
		return (fixed2);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	else
		return (fixed2);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	else
		return (fixed2);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	else
		return (fixed2);
}
