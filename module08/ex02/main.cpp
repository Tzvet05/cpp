#include <iostream>
#include <list>
#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack1;
	mstack1.push(1);
	mstack1.push(2);
	mstack1.push(3);
	MutantStack<int>::reverse_iterator	rit = mstack1.rbegin();
	MutantStack<int>::reverse_iterator	rite = mstack1.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	mstack1.pop();
	MutantStack<int>::iterator	it = mstack1.begin();
	MutantStack<int>::iterator	ite = mstack1.end();
	std::cout << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "With a MutantStack :" << std::endl;

	MutantStack<int>	mstack2;
	mstack2.push(5);
	mstack2.push(17);
	std::cout << mstack2.top() << std::endl;
	mstack2.pop();
	std::cout << mstack2.size() << std::endl;
	std::cout << mstack2.top() << std::endl;
	mstack2.push(3);
	mstack2.push(5);
	mstack2.push(737);
	mstack2.push(0);
	it = mstack2.begin();
	ite = mstack2.end();
	++it;
	--it;
	std::cout << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack2);

	std::cout << "With a std::list :" << std::endl;

	std::list<int>	list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	std::cout << list.back() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator	it_list = list.begin();
	std::list<int>::iterator	ite_list = list.end();
	++it_list;
	--it_list;
	std::cout << std::endl;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	return (0);
}
