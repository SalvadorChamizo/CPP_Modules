/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:52:20 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/09 15:11:25 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main( void )
{
	int		array1[] = {1, 2, 3, 4, 5};
	double array2[] = {2.3, 5.4, 7.1, 8.9};

	iter(array1, 5, print);
	iter(array1, 5, sumOneToAll);
	iter(array1, 5, print<int>);
	iter(array2, 4, print);
}