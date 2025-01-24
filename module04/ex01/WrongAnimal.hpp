#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wrongAnimal);
		WrongAnimal& operator=(const WrongAnimal&);
		virtual ~WrongAnimal(void);

		std::string	getType(void) const;

		void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif
