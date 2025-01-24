#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal& animal);
		Animal& operator=(const Animal&);
		virtual ~Animal(void);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif
