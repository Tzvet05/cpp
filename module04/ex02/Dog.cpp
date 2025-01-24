#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void)
{
	std::cout << "Dog: default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog: copy constructor called" << std::endl;
	_type = dog._type;
	_brain = new Brain(*dog._brain);
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog: destructor called" << std::endl;
	delete _brain;
}

std::string	Dog::getType(void) const
{
	return (_type);
}

Brain*	Dog::getBrain(void) const
{
	return (_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Bark !" << std::endl;
}
