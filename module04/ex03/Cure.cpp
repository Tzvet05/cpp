#include <iostream>
#include "Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
}

Cure::Cure(const Cure& cure)
{
	_type = cure._type;
}

Cure&	Cure::operator=(const Cure& rhs)
{
	(void)rhs;
	return (*this);
}

Cure::~Cure(void)
{
}

AMateria*	Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}
