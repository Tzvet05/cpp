#ifndef __AANIMAL_H__
#define __AANIMAL_H__

#include <string>

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal& animal);
		AAnimal& operator=(const AAnimal&);
		virtual ~AAnimal(void);

		std::string	getType(void) const;

		virtual void	makeSound(void) const = 0;
	protected:
		std::string	_type;
};

#endif
