#pragma once

#include <cstring>
#include <exception>
#include <string.h>
#include <sys/types.h>

template <typename T>
class	Array
{
	public:
		Array(void)
		{
			_size = 0;
			_buffer = new T[_size];
		}
		Array(const Array& array)
		{
			_size = array._size;
			_buffer = new T[_size];
			std::memcpy(_buffer, array._buffer, _size * sizeof(T));
		}
		Array& operator=(const Array& rhs)
		{
			if (this != &rhs)
			{
				_size = rhs._size;
				delete[] _buffer;
				_buffer = new T[_size];
				std::memcpy(_buffer, rhs._buffer, _size * sizeof(T));
			}
			return (*this);
		}
		~Array(void)
		{
			delete[] _buffer;
		}

		Array(unsigned int n)
		{
			_size = n;
			_buffer = new T[_size];
			bzero(_buffer, _size * sizeof(T));
		}

		size_t	size(void) const
		{
			return (_size);
		}

		T& operator[](ssize_t index) const
		{
			if (index < 0 || (size_t)index >= _size)
				throw (IndexOutOfBoundsException());
			return (_buffer[index]);
		}

	private:
		size_t	_size;
		T*	_buffer;

		class	IndexOutOfBoundsException: public std::exception
		{
			public:
				IndexOutOfBoundsException(void) {}

				const char*	what(void) const throw()
				{
					return ("Index given is out-of-bounds");
				}
		};
};
