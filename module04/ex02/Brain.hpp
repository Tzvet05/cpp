#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <string>

class	Brain
{
	public:
		Brain(void);
		Brain(const Brain& brain);
		Brain& operator=(const Brain&);
		~Brain(void);

		std::string*	getIdeas(void);

		void		setIdeas(std::string* ideas);
	private:
		std::string	_ideas[100];
};

#endif
