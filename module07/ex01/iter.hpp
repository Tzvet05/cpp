#pragma once

template <typename TypeArr, typename TypeLen, typename TypeFunc>
void	iter(TypeArr* arr, TypeLen len, TypeFunc func)
{
	for (TypeLen i = 0; i < len; i++)
		func(arr[i]);
}

template <typename Type>
void	print(const Type& to_print)
{
	std::cout << to_print << std::endl;
}

template <typename Type>
void	inc(Type& to_inc)
{
	to_inc++;
}
