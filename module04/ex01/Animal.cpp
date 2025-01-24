#include <iostream>
#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal: default constructor called" << std::endl;
	_type = "Animal";
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal: copy constructor called" << std::endl;
	_type = animal._type;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal: copy assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal: destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal: * generic animal noises *" << std::endl;
}
