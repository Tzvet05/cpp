#pragma once

template <typename Type>
void	swap(Type& elem1, Type& elem2)
{
	Type	elem_tmp = elem1;
	elem1 = elem2;
	elem2 = elem_tmp;
}

template <typename Type>
Type	min(Type elem1, Type elem2)
{
	if (elem1 < elem2)
		return (elem1);
	return (elem2);
}

template <typename Type>
Type	max(Type elem1, Type elem2)
{
	if (elem1 > elem2)
		return (elem1);
	return (elem2);
}
