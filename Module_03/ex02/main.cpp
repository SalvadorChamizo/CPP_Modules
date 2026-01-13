/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:46:18 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/19 17:53:40 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap manolo("Manolo");
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
	manolo.highFivesGuys();
	manolo.attack("Pepe");
	pepe.takeDamage(manolo.getDamage());
	manolo.highFivesGuys();
	pepe.attack("Manolo");
	manolo.takeDamage(pepe.getDamage());
	pepe.beRepaired(20);
	manolo.setDamage(100);
	manolo.attack("Pepe");
	pepe.takeDamage(manolo.getDamage());
	pepe.attack("Manolo");
}