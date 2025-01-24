#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain: copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; i++)
			_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain: destructor called" << std::endl;
}

std::string*	Brain::getIdeas(void)
{
	return (_ideas);
}

void	Brain::setIdeas(std::string* ideas)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = ideas[i];
}
