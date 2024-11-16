/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:08:37 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/17 16:28:46 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie* newZombie(std::string name);

int	main(void)
{
	Zombie	*HeapAllocated;

	HeapAllocated = newZombie("Heap");
	HeapAllocated->announce();

	randomChump("Stack");

	delete(HeapAllocated);
	return (0);
}