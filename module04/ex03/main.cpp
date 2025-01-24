#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	std::cout << "========== MateriaSource ==========" << std::endl;
	IMateriaSource* src = new MateriaSource();

	AMateria* tmp;
	tmp = new Ice();
	src->learnMateria(tmp);
	src->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	src->learnMateria(tmp);
	src->learnMateria(tmp);
	src->learnMateria(tmp);
	src->learnMateria(NULL);
	delete tmp;

	MateriaSource* obj1 = new MateriaSource();
	tmp = new Ice();
	obj1->learnMateria(tmp);
	delete tmp;
	MateriaSource* obj2 = new MateriaSource(*obj1);
	tmp = obj2->createMateria("ice");
	delete tmp;
	tmp = new Cure();
	obj2->learnMateria(tmp);
	delete tmp;
	*obj1 = *obj2;
	delete obj2;
	tmp = obj1->createMateria("cure");
	delete tmp;
	delete obj1;

	std::cout << "========== Character ==========" << std::endl;
	ICharacter* karl = new Character("Karl");

	tmp = src->createMateria("ice");
	karl->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	karl->equip(tmp);
	delete tmp;
	tmp = src->createMateria("ice");
	karl->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	karl->equip(tmp);
	delete tmp;
	tmp = src->createMateria("ice");
	karl->equip(tmp);
	delete tmp;
	tmp = src->createMateria("nothing");
	karl->equip(tmp);
	delete tmp;

	Character* john = new Character("John");
	tmp = src->createMateria("ice");
	john->equip(tmp);
	delete tmp;
	Character* john2 = new Character(*john);
	tmp = src->createMateria("cure");
	john2->equip(tmp);
	delete tmp;
	*john = *john2;
	delete john2;
	tmp = src->createMateria("ice");
	john->equip(tmp);
	john->equip(tmp);
	john->equip(tmp);
	delete tmp;

	std::cout << "========== Use ==========" << std::endl;
	Character* empty = new Character();
	karl->use(0, *john);
	karl->use(1, *john);
	karl->use(-2, *john);
	empty->use(2, *karl);

	std::cout << "========== Garbage Collector ==========" << std::endl;
	empty->unequip(2);
	john->unequip(8);
	john->unequip(1);
	john->unequip(2);
	Character* john3 = new Character("John3");
	*john3 = *john;
	john3->unequip(0);
	john3->unequip(1);
	delete john3;

	delete john;
	delete karl;
	delete empty;
	delete src;
	return (0);
}
