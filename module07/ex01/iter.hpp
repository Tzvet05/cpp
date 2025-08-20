#pragma once

template <typename Type>
void	iter(const Type* arr, size_t len, void (*f)(const Type&))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename Type>
void	iter(Type* arr, size_t len, void (*f)(Type&))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
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

template <typename Type>
void	dec(Type& to_dec)
{
	to_dec--;
}
