/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:34:28 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/17 17:38:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int		i;
	int		zombieNum;
	Zombie	*horde;

	i = 0;
	zombieNum = 5;
	horde = zombieHorde(zombieNum, "Paco");
	while (i < zombieNum)
	{
		horde[i].announce();
		i++;
	}
	delete [](horde);
	return (0);
}