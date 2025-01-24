#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal*	a = new Animal();
	const Animal*	d = new Dog();
	const Animal*	c = new Cat();

	std::cout << a->getType() << std::endl;
	std::cout << d->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	d->makeSound();
	c->makeSound();
	a->makeSound();

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wa->getType() << std::endl;
	std::cout << wc->getType() << std::endl;
	wc->makeSound();
	wa->makeSound();

	const Dog*	d2 = new Dog();
	const Animal*	d3 = new Dog(*d2);

	std::cout << d2->getType() << std::endl;
	std::cout << d3->getType() << std::endl;
	d2->makeSound();
	d3->makeSound();

	delete a;
	delete d;
	delete c;
	delete wa;
	delete wc;
	delete d2;
	delete d3;
	return (0);
}
