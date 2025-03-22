#pragma once

#include <string>

class	Data
{
	public:
		Data(void);
		Data(const Data& data);
		Data& operator=(const Data&);
		~Data(void);

		Data(const std::string& name, size_t len);

		void	setName(const std::string& name);
		void	setLen(size_t len);
		std::string	getName(void) const;
		size_t		getLen(void) const;
	private:
		std::string	_name;
		size_t		_len;
};
