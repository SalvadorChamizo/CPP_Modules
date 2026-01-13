/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:47 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/25 16:57:01 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	std::string		line;
	std::stack<int> stack;

	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments.\n";
		return (1);
	}

	line = argv[1];
	try
	{
		parseExpression(line);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what();
		return (1);
	}
}
