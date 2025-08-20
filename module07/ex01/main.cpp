#include <iostream>
#include "iter.hpp"

int	main(void)
{
	int		arr[] = {1, 2, 3, 4};
	iter(arr, 4, inc<int>);
	iter(arr, 4, print<int>);
	iter(arr, 2, dec<int>);
	iter(arr, 4, print<int>);
	const std::string	arr_const[] = {"a", "b", "c", "d"};
	iter(arr_const, 3, print<std::string>);
	return (0);
}
