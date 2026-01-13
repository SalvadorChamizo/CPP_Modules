/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:27:41 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/19 17:31:02 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap pepe("Pepe");
	ClapTrap paco("Paco");
	int	i = 0;

	pepe.attack("Paco");
	paco.takeDamage(pepe.getDamage());
	paco.attack("Pepe");
	pepe.takeDamage(paco.getDamage());
	paco.beRepaired(1);
	while (i < 4)
	{
		pepe.attack("Paco");
		i++;
	}
	pepe.guardGate();
	paco.takeDamage(i * pepe.getDamage());
	paco.beRepaired(10);
}