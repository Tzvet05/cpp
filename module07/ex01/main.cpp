#include <iostream>
#include "iter.hpp"

int	main(void)
{
	int		arr[] = {1, 2, 3, 4};
	iter(arr, 4, inc<int>);
	iter(arr, 4, print<int>);
	const int	arr_const[] = {1, 2, 3, 4};
	iter(arr_const, 4, print<int>);
	return (0);
}
