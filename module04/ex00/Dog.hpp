#ifndef __DOG_H__
#define __DOG_H__

#include <string>
#include "Animal.hpp"

class	Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& dog);
		Dog& operator=(const Dog&);
		~Dog(void);

		std::string	getType(void) const;

		void	makeSound(void) const;
};

#endif
