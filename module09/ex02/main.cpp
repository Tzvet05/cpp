#include <iostream>
#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	static_cast<void>(argc);
	try
	{
		PmergeMeVector	pmergeme_vector(&argv[1]);
		PmergeMeDeque	pmergeme_deque(&argv[1]);
		std::cout << "Integer sequence before sorting: " << pmergeme_vector.print()
			<< std::endl;
		pmergeme_vector.sort();
		pmergeme_deque.sort();
		std::cout << "Integer sequence after sorting:  " << pmergeme_vector.print()
			<< std::endl;
		std::cout << "Time to process a range of " << pmergeme_vector.get_vector().size()
			<< " elements with container std::vector<int>: "
			<< pmergeme_vector.get_duration() << " us" << std::endl;
		std::cout << "Time to process a range of " << pmergeme_deque.get_deque().size()
			<< " elements with container std::deque<int>:  "
			<< pmergeme_deque.get_duration() << " us" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
