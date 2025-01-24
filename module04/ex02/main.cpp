#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
//	AAnimal	animal;

	AAnimal	*animals[10];
	std::string	ideas[100];

	for (size_t i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (size_t i = 5; i < 10; i++)
		animals[i] = new Cat();

	ideas[0] = "Woof";
	ideas[1] = "Woaf";
	ideas[3] = "Waf";

	Dog	dog;
	dog.getBrain()->setIdeas(ideas);
	Dog	dogCopy = Dog(dog);
	std::cout << dogCopy.getBrain()->getIdeas()[0] << std::endl;
	std::cout << dogCopy.getBrain()->getIdeas()[1] << std::endl;
	std::cout << dogCopy.getBrain()->getIdeas()[2] << std::endl;
	std::cout << dogCopy.getBrain()->getIdeas()[3] << std::endl;

	Cat	cat;
	Cat	catCopy;
	catCopy = cat;

	for (size_t i = 0; i < 10; i++)
		delete animals[i];
	return (0);
}
