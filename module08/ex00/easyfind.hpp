#pragma once

#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int to_find)
{
	return (std::find(container.begin(), container.end(), to_find));
}
