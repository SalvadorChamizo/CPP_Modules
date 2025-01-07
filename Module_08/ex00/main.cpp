/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:45:00 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/07 15:06:02 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main(void)
{
	int vectArray[] = {1, 3, 2, 0, 5};
	std::vector<int> vect(vectArray, vectArray + sizeof(vectArray) / sizeof(int));

	int listArray[] = {1, 2, 0, -1, 5};
	std::list<int> list(listArray, listArray + sizeof(listArray) / sizeof(int));

	std::vector<int>::iterator i;
	std::list<int>::iterator j;

	std::cout << "Test 1: ";
	i = easyfind(vect, 0);
	if (i == vect.end())
		std::cout << "Not found.\n";
	else
		std::cout << "Found.\n";


	std::cout << "\nTest 2: ";
	j = easyfind(list, 3);
	if (j == list.end())
		std::cout << "Not found.\n";
	else
		std::cout << "Found.\n";
}