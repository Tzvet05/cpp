/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:24:50 by ttrave            #+#    #+#             */
/*   Updated: 2024/11/28 17:57:34 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phoneBook.hpp"
#include "contact.hpp"

static int	CheckCommand(std::string Input, std::string Syntax)
{
	size_t	i_input;
	size_t	i_syntax;

	i_input = 0;
	while (Input.c_str()[i_input] != '\0' && isspace(Input.c_str()[i_input]) != 0)
		i_input++;
	i_syntax = 0;
	while (Syntax.c_str()[i_syntax] != '\0')
	{
		if (Input.c_str()[i_input] != Syntax.c_str()[i_syntax])
			return (1);
		i_input++;
		i_syntax++;
	}
	while (Input.c_str()[i_input] != '\0' && isspace(Input.c_str()[i_input]) != 0)
		i_input++;
	if (Input.c_str()[i_input] != '\0')
		return (1);
	return (0);
}

int	main(void)
{
	PhoneBook	MyPhoneBook;
	std::string	Input;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT) :" << std::endl << "> ";
		std::getline(std::cin, Input);
		if (std::cin.eof() == 1)
			break ;
		if (CheckCommand(Input, "ADD") == 0)
		{
			if (MyPhoneBook.Add() == 1)
				return (0);
		}
		else if (CheckCommand(Input, "SEARCH") == 0)
			MyPhoneBook.Search();
		else if (CheckCommand(Input, "EXIT") == 0)
			break ;
		else
			std::cout << "\"" << Input << "\" is not a supported command." << std::endl;
	}
	return (0);
}
