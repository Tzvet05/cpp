#include <iostream>
#include <ctime>
#include <deque>
#include "Span.hpp"

int	main(void)
{
	Span	span1;

	Span	span2(3);
	span2.addNumber(50);
	span2.addNumber(-14);
	span2.addNumber(317);
	try
	{
		span2.addNumber(8);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	const int	arr[] = {6, -1, 75, -391, 4, 36, -2};
	std::deque<int>	deq(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Span	span3(10);
	span3.addNumber(69);
	span3.addNumber(-15);
	span3.addNumbersRange(deq.begin(), deq.end());
	try
	{
		span3.addNumbersRange(deq.begin(), deq.end());
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::srand(std::time(NULL));
	Span	span4(50000);
	for (size_t i = 0; i < 50000; i++)
	{
		int	rand = std::rand();
		if (std::rand() & 1)
			rand = -rand;
		span4.addNumber(rand);
	}

	try
	{
		std::cout << span1.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << span1.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << span2.shortestSpan() << std::endl;
	std::cout << span2.longestSpan() << std::endl;
	std::cout << span3.shortestSpan() << std::endl;
	std::cout << span3.longestSpan() << std::endl;
	std::cout << span4.shortestSpan() << std::endl;
	std::cout << span4.longestSpan() << std::endl;
	return (0);
}
