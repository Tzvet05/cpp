#include <iostream>

int	main( void )
{
	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory address of the string :     " << &string << std::endl;
	std::cout << "Memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF : " << &stringREF << std::endl;

	std::cout << "Value of the string :              " << string << std::endl;
	std::cout << "Value pointed to by stringPTR :    " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF :    " << stringREF << std::endl;
	return (0);
}
