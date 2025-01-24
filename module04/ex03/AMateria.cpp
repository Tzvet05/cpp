#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void)
{
	_type = "Materia";
}

AMateria::AMateria(const AMateria& materia)
{
	_type = materia._type;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	(void)rhs;
	return (*this);
}

AMateria::~AMateria(void)
{
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
}

std::string const &	AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses a materia targeted at " << target.getName() << " *" << std::endl;
}
