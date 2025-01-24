#include <iostream>
#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat: default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	_type = cat._type;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat: copy assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat: destructor called" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (_type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow !" << std::endl;
}
