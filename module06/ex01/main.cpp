#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data	data("Data", 10);
	Data*	ptr = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << "Original data pointer :\t\t" << &data << std::endl;
	std::cout << "Deserialized data pointer :\t" << ptr << std::endl;
	return (0);
}
