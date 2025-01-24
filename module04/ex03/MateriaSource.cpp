#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i < 4; i++)
		_knownMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	size_t	i = 0;
	while (i < 4 && materiaSource._knownMaterias[i] != NULL)
	{
		_knownMaterias[i] = materiaSource._knownMaterias[i]->clone();
		i++;
	}
	while (i < 4)
	{
		_knownMaterias[i] = NULL;
		i++;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		size_t	i = 0;
		while (i < 4 && _knownMaterias[i] != NULL)
		{
			delete _knownMaterias[i];
			i++;
		}
		i = 0;
		while (i < 4 && rhs._knownMaterias[i] != NULL)
		{
			_knownMaterias[i] = rhs._knownMaterias[i]->clone();
			i++;
		}
		while (i < 4)
		{
			_knownMaterias[i] = NULL;
			i++;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	size_t	i = 0;
	while (i < 4 && _knownMaterias[i] != NULL)
	{
		delete _knownMaterias[i];
		i++;
	}
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL)
	{
		std::cout << "MateriaSource: NULL argument: the pointer to the materia to learn is NULL (pointer must point to a materia)" << std::endl;
		return;
	}
	size_t	i = 0;
	while (i < 4 && _knownMaterias[i] != NULL)
		i++;
	if (i == 4)
	{
		std::cout << "MateriaSource: max knowledge: knowledge space already filled with 4 materias (create a new MateriaSource to store more materias)" << std::endl;
		return;
	}
	_knownMaterias[i] = materia->clone();
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	size_t	i = 0;
	while (i < 4 && _knownMaterias[i]->getType() != type)
		i++;
	if (i == 4)
	{
		std::cout << "MateriaSource: unknown type: materia type \"" << type << "\" has not been learned previously and is therefore unknown (learn the type first or specify an already learned type)" << std::endl;
		return (NULL);
	}
	return (_knownMaterias[i]->clone());
}
