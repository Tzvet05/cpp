#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
	std::cout << "Cat: default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	_type = cat._type;
	_brain = new Brain(*cat._brain);
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat: destructor called" << std::endl;
	delete _brain;
}

std::string	Cat::getType(void) const
{
	return (_type);
}

Brain*	Cat::getBrain(void) const
{
	return (_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow !" << std::endl;
}
