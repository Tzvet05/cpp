#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat: default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
	std::cout << "WrongCat: copy constructor called" << std::endl;
	_type = wrongCat._type;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat: copy assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: destructor called" << std::endl;
}

std::string	WrongCat::getType(void) const
{
	return (_type);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: Meow !" << std::endl;
}
