/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:27:27 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/19 17:47:32 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {

	protected:
		std::string	_name;
		int			_hit_points;
		int			_energy;
		int			_damage;

	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &other);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int		getDamage(void);
		void	setDamage(unsigned int damage);
};

#endif
