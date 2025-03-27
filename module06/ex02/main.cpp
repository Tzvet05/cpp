#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base*	generate(void)
{
	std::srand(std::time(NULL));
	if ((std::rand() % 3) == 0)
		return (new A());
	else if ((std::rand() % 3 == 1))
		return (new B());
	else
		return (new C());
}

static void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

static void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
}

int	main(void)
{
	Base*	base1 = generate();
	identify(base1);
	identify(*base1);
	delete base1;
	return (0);
}
