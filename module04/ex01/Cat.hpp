#ifndef __CAT_H__
#define __CAT_H__

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& cat);
		Cat& operator=(const Cat&);
		~Cat(void);

		std::string	getType(void) const;
		Brain*		getBrain(void) const;

		void	makeSound(void) const;
	private:
		Brain*	_brain;
};

#endif
