#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <string>
#include "ICharacter.hpp"

class	AMateria
{
	public:
		AMateria(void);
		AMateria(const AMateria& materia);
		AMateria& operator=(const AMateria&);
		virtual ~AMateria(void);

		AMateria(std::string const & type);

		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
	protected:
		std::string	_type;
};

#endif
