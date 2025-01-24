#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class	Weapon {
	public:
		Weapon( std::string type );
		~Weapon( void );

		const std::string&	getType( void ) const;
		void			setType(const std::string type);
	private:
		std::string	_type;
};

#endif
