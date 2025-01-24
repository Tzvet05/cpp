#include <iostream>
#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog: default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog: copy constructor called" << std::endl;
	_type = dog._type;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog: copy assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog: destructor called" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (_type);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Bark !" << std::endl;
}
