/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:07:15 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/26 19:18:56 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap antonio("Antonio");
	FragTrap manolo("Manolo");
	ScavTrap pepe("Pepe");
	ClapTrap paco("Paco");
	int	i = 0;

	antonio.whoAmI();
	pepe.attack("Paco");
	paco.takeDamage(pepe.getDamage());
	paco.attack("Pepe");
	pepe.takeDamage(paco.getDamage());
	antonio.attack("Manolo");
	manolo.takeDamage(antonio.getDamage());
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
