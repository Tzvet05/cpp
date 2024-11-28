/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:45:04 by ttrave            #+#    #+#             */
/*   Updated: 2024/10/24 20:02:54 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "phoneBook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook(void)
{
	_Size = 0;
	_Oldest = 0;
}

PhoneBook::~PhoneBook(void)
{
}

static std::string	GetInputString(std::string Prompt, size_t *Error)
{
	std::string	Input;

	while (1)
	{
		std::cout << Prompt << std::endl << "> ";
		std::getline(std::cin, Input);
		if (Input.length() > 0)
			break ;
		if (std::cin.eof() == 1)
		{
			*Error = 1;
			break ;
		}
		std::cout << "A saved contact cannot have empty fields." << std::endl;
	}
	return (Input);
}

int	PhoneBook::Add(void)
{
	std::string	Input;
	Contact	BufferContact;
	size_t		Error;

	Error = 0;
	BufferContact.SetFirstName(GetInputString("Enter a first name :", &Error));
	if (Error == 1)
		return (1);
	BufferContact.SetLastName(GetInputString("Enter a last name :", &Error));
	if (Error == 1)
		return (1);
	BufferContact.SetNickname(GetInputString("Enter a nickname :", &Error));
	if (Error == 1)
		return (1);
	BufferContact.SetPhoneNumber(GetInputString("Enter a phone number :", &Error));
	if (Error == 1)
		return (1);
	BufferContact.SetDarkestSecret(GetInputString("Enter a darkest secret :", &Error));
	if (Error == 1)
		return (1);
	if (_Size < 8)
	{
		_ContactsList[_Size] = BufferContact;
		_Size++;
	}
	else
	{
		_ContactsList[_Oldest] = BufferContact;
		_Oldest++;
		if (_Oldest > 7)
			_Oldest = 0;
	}
	return (0);
}

static size_t	AtoiInput(std::string InputIndex)
{
	size_t	n;
	size_t	i;

	i = 0;
	while (InputIndex.c_str()[i] != '\0' && isspace(InputIndex.c_str()[i]) != 0)
		i++;
	if (InputIndex.c_str()[i] < '0' || InputIndex.c_str()[i] > '7')
		return (8);
	n = InputIndex.c_str()[i] - '0';
	i++;
	while (InputIndex.c_str()[i] != '\0' && isspace(InputIndex.c_str()[i]) != 0)
		i++;
	if (InputIndex.c_str()[i] != '\0')
		return (8);
	return (n);
}

static void	DisplayField(std::string Output)
{
	if (Output.length() > 10)
	{
		Output.resize(10);
		Output[9] = '.';
	}
	std::cout << std::setw(10) << Output << "|";
}

void	PhoneBook::Search(void)
{
	std::string	Input;
	std::string	Buffer;
	size_t	i;

	std::cout << std::setiosflags(std::ios::right);
	DisplayField("Index");
	DisplayField("First name");
	DisplayField("Last name");
	DisplayField("Nickname");
	std::cout << std::endl;
	i = 0;
	while (i < _Size)
	{
		std::cout << std::setw(10) << i << "|";
		DisplayField(_ContactsList[i].GetFirstName());
		DisplayField(_ContactsList[i].GetLastName());
		DisplayField(_ContactsList[i].GetNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << std::resetiosflags(std::ios::right);
	std::cout << "Enter the index of the entry to display :" << std::endl << "> ";
	std::getline(std::cin, Input);
	if (std::cin.eof() == 1)
		return ;
	i = AtoiInput(Input);
	if (i >= _Size)
		std::cout << "\"" << Input << "\" is not a valid index. Search mode closed." << std::endl;
	else
		std::cout << "First name : " << _ContactsList[i].GetFirstName() << std::endl << "Last name : " <<  _ContactsList[i].GetLastName() << std::endl << "Nickname : " << _ContactsList[i].GetNickname() << std::endl << "Phone number : " << _ContactsList[i].GetPhoneNumber() << std::endl << "Darkest secret : " << _ContactsList[i].GetDarkestSecret() << std::endl;
}
