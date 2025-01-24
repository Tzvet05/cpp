#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include "ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		Character(void);
		Character(const Character& character);
		Character& operator=(const Character&);
		~Character(void);

		Character(const std::string name);

		std::string const &	getName() const;
		void			equip(AMateria* m);
		void			unequip(int idx);
		void			use(int idx, ICharacter& target);
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		AMateria**	_garbageCollector;
		size_t		_nGarbageCollected;
		size_t		_sizeGarbageCollector;
};

#endif
