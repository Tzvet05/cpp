/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:41:14 by ttrave            #+#    #+#             */
/*   Updated: 2024/10/24 16:17:51 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		void		SetFirstName(std::string FirstName);
		void		SetLastName(std::string LastName);
		void		SetNickname(std::string Nickname);
		void		SetPhoneNumber(std::string PhoneNumber);
		void		SetDarkestSecret(std::string DarkestSecret);
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickname(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
};

#endif
