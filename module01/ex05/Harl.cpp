#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::_other(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	Harl	harl;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*comments[]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error, &Harl::_other};

	size_t	i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	(harl.*comments[i])();
}
