#include "Data.hpp"

Data::Data(void)
{
	_name = "Name";
	_len = 0;
}

Data::Data(const Data& data)
{
	_name = data._name;
	_len = data._len;
}

Data& Data::operator=(const Data& rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_len = rhs._len;
	}
	return (*this);
}

Data::~Data(void) {}

Data::Data(const std::string& name, size_t len)
{
	_name = name;
	_len = len;
}

void	Data::setName(const std::string& name)
{
	_name = name;
}

void	Data::setLen(size_t len)
{
	_len = len;
}

std::string	Data::getName(void) const
{
	return (_name);
}

size_t	Data::getLen(void) const
{
	return (_len);
}
