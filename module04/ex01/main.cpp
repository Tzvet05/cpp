#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal	*animals[10];
	std::string	ideas[100];

	for (size_t i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (size_t i = 5; i < 10; i++)
		animals[i] = new Cat();

	ideas[0] = "Woof";
	ideas[1] = "Woaf";

	Dog	dog;
	dog.getBrain()->setIdeas(ideas);
	Dog	dogCopy = Dog(dog);

	std::cout << "Dog :" << std::endl;
	std::cout << dog.getBrain()->getIdeas()[0] << std::endl;
	std::cout << dog.getBrain()->getIdeas()[1] << std::endl;
	std::cout << "DogCopy :" << std::endl;
	std::cout << dogCopy.getBrain()->getIdeas()[0] << std::endl;
	std::cout << dogCopy.getBrain()->getIdeas()[1] << std::endl;

	std::cout << "Dog's ideas changed" << std::endl;
	ideas[1] = "Meow ?";

	dog.getBrain()->setIdeas(ideas);
	std::cout << "Dog :" << std::endl;
	std::cout << dog.getBrain()->getIdeas()[0] << std::endl;
	std::cout << dog.getBrain()->getIdeas()[1] << std::endl;
	std::cout << "DogCopy :" << std::endl;
	std::cout << dogCopy.getBrain()->getIdeas()[0] << std::endl;
	std::cout << dogCopy.getBrain()->getIdeas()[1] << std::endl;

	Cat	cat;
	Cat	catCopy;
	catCopy = cat;

	for (size_t i = 0; i < 10; i++)
		delete animals[i];
	return (0);
}
