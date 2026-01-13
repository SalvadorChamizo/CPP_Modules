/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:07:08 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/17 18:26:57 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str;
	std::string *stringPTR;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "String memory address: " << &str << std::endl;
	std::cout << "PTR memory address: " << stringPTR << std::endl;
	std::cout << "REF memory address: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String value: " << str << std::endl;
	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl;
	return (0);
}
