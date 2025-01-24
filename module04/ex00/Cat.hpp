#ifndef __CAT_H__
#define __CAT_H__

#include <string>
#include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& cat);
		Cat& operator=(const Cat&);
		~Cat(void);

		std::string	getType(void) const;

		void	makeSound(void) const;
};

#endif
