#include <iostream>
#include "Ice.hpp"

Ice::Ice(void)
{
	_type = "ice";
}

Ice::Ice(const Ice& ice)
{
	_type = ice._type;
}

Ice&	Ice::operator=(const Ice& rhs)
{
	(void)rhs;
	return (*this);
}

Ice::~Ice(void)
{
}

AMateria*	Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
