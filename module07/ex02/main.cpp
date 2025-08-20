#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<int>	arr1;
	try
	{
		std::cout << arr1[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Array<int>	arr2(5);
	arr2[1] = 6;
	arr2[3] = 18;
	arr1 = arr2;
	Array<int>	arr3(arr2);
	std::cout << arr1[0] << std::endl;
	std::cout << arr1[1] << std::endl;
	std::cout << arr1[3] << std::endl;
	std::cout << arr3[0] << std::endl;
	std::cout << arr3[1] << std::endl;
	std::cout << arr3[3] << std::endl;
	arr1[3] = 264;
	arr3[3] = -2;
	std::cout << arr1[3] << std::endl;
	std::cout << arr3[3] << std::endl;
	std::cout << arr2[3] << std::endl;
	std::cout << arr1.size() << std::endl;
	const Array<int>	const_arr(arr2);
	std::cout << const_arr[1] << std::endl;
	Array<float>	arrf(3);
	arrf[1] = 5.2f;
	std::cout << arrf[1] << std::endl;
	return (0);
}
