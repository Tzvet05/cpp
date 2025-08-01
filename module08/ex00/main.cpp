#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vec;
	vec.push_back(8);
	vec.push_back(-2);
	vec.push_back(65);
	std::vector<int>::iterator	it_vec = easyfind(vec, -2);
	if (it_vec != vec.end())
		std::cout << *it_vec << std::endl;
	else
		std::cout << "Element not found" << std::endl;
	it_vec = easyfind(vec, 5);
	if (it_vec != vec.end())
		std::cout << *it_vec << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	std::deque<int>	deq;
	deq.push_back(8);
	deq.push_back(-2);
	deq.push_back(65);
	std::deque<int>::iterator	it_deq = easyfind(deq, 65);
	if (it_deq != deq.end())
		std::cout << *it_deq << std::endl;
	else
		std::cout << "Element not found" << std::endl;
	it_deq = easyfind(deq, 5);
	if (it_deq != deq.end())
		std::cout << *it_deq << std::endl;
	else
		std::cout << "Element not found" << std::endl;
	return (0);
}
