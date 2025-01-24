#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

#include <string>
#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& wrongcat);
		WrongCat& operator=(const WrongCat&);
		~WrongCat(void);

		std::string	getType(void) const;

		void	makeSound(void) const;
};

#endif
