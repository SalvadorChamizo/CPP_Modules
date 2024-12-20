/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:57:45 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/09 17:18:42 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <string>

int	main(void)
{
	int i = 0;
	double k = 1.1;

	Array<int> array1(5);
	Array<double> array2(4);
	Array<std::string> array3(3);

	std::cout << "\n";
	try
	{
		array1[5] = 1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	while (i < array1.size())
	{
		array1[i] = i + 1;
		i++;
	}

	i = 0;
	while (i < array2.size())
	{
		array2[i] = k + 1.0;
		i++;
		k++;
	}

	array3[0] = "Hola ";
	array3[1] = "mundo";
	array3[2] = ", adios";
	for (int j = 0; j < array1.size(); j++)
		std::cout << array1[j] << " ";
	std::cout << "\n";

	for (int j = 0; j < array2.size(); j++)
		std::cout << array2[j] << " ";
	std::cout << "\n";

	for (int j = 0; j < array3.size(); j++)
		std::cout << array3[j];
	std::cout << "\n";
	
	return (0);
}