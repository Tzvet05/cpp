/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:41:17 by ttrave            #+#    #+#             */
/*   Updated: 2024/10/24 16:08:42 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::SetFirstName(std::string FirstName)
{
	_FirstName = FirstName;
}

void	Contact::SetLastName(std::string LastName)
{
	_LastName = LastName;
}

void	Contact::SetNickname(std::string Nickname)
{
	_Nickname = Nickname;
}

void	Contact::SetPhoneNumber(std::string PhoneNumber)
{
	_PhoneNumber = PhoneNumber;
}

void	Contact::SetDarkestSecret(std::string DarkestSecret)
{
	_DarkestSecret = DarkestSecret;
}

std::string	Contact::GetFirstName(void)
{
	return (_FirstName);
}

std::string	Contact::GetLastName(void)
{
	return (_LastName);
}

std::string	Contact::GetNickname(void)
{
	return (_Nickname);
}

std::string	Contact::GetPhoneNumber(void)
{
	return (_PhoneNumber);
}

std::string	Contact::GetDarkestSecret(void)
{
	return (_DarkestSecret);
}
