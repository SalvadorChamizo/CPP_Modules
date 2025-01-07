/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:28:56 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/19 12:24:02 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap pepe("Pepe");
	ClapTrap paco("Paco");

	pepe.setDamage(1);
	paco.setDamage(1);
	pepe.attack("Paco");
	paco.takeDamage(pepe.getDamage());
	paco.attack("Pepe");
	pepe.takeDamage(paco.getDamage());
	paco.beRepaired(1);
	for (int i = 0; i < 10; i++)
		pepe.attack("Paco");
	paco.takeDamage(10);
	paco.beRepaired(10);
}