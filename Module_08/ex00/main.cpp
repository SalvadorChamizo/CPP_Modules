/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:45:00 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/13 11:40:21 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main(void)
{
	std::vector<int> vect = {1, 3, 2, 0, 5};
	std::list<int> list = {1, 2, 0, -1, 5};
	std::vector<int>::iterator i;
	std::list<int>::iterator j;

	std::cout << "Test 1: ";
	i = easyfind(vect, 0);
	if (i == end(vect))
		std::cout << "Not found.\n";
	else
		std::cout << "Found.\n";


	std::cout << "\nTest 2: ";
	j = easyfind(list, 3);
	if (j == end(list))
		std::cout << "Not found.\n";
	else
		std::cout << "Found.\n";
}