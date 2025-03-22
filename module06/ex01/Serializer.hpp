#pragma once

#include <stdint.h>

class	Data;

class	Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	protected:
		Serializer(void);
		Serializer(const Serializer& serializer);
		Serializer& operator=(const Serializer&);
		~Serializer(void);
};
