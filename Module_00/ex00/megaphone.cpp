/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:49:26 by schamizo          #+#    #+#             */
/*   Updated: 2024/09/24 17:44:18 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_upper(std::string &str)
{
	unsigned long	i;

	i = 0;
	while (i < str.length())
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
		i++;
	}
	std::cout << str; 
}

int	main(int argc, char **argv)
{
	std::string	str;
	int	i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		while (i < argc)
		{
			str = argv[i];
			ft_upper(str);
			i++; 
		}
	}
	std::cout << std::endl;
	return (0);
}
