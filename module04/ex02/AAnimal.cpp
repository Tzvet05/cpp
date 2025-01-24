#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal: default constructor called" << std::endl;
	_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& animal)
{
	std::cout << "AAnimal: copy constructor called" << std::endl;
	_type = animal._type;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "AAnimal: copy assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal: destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}
