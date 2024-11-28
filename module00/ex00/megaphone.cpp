/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:22:29 by ttrave            #+#    #+#             */
/*   Updated: 2024/10/22 19:11:20 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; i < (size_t)argc; i++)
			for (size_t j = 0; j < std::strlen(argv[i]); j++)
				std::cout << (char)std::toupper(argv[i][j]);
		std::cout << std::endl;
	}
	return (0);
}
