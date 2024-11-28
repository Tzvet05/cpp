/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:45:54 by ttrave            #+#    #+#             */
/*   Updated: 2024/10/24 20:01:55 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int	Add(void);
		void	Search(void);
	private:
		Contact	_ContactsList[8];
		size_t	_Size;
		size_t	_Oldest;
};
