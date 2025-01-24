#ifndef __ICE_H__
#define __ICE_H__

#include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& ice);
		Ice& operator=(const Ice&);
		~Ice(void);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
