/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:40:03 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/21 15:46:25 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# pragma once
# include <iostream>
# include <string>

class	Weapon {

	private:

		std::string	_type;

	public:

		Weapon(void);
		Weapon(std::string const type);
		~Weapon(void);
		std::string const &getType(void) const;
		void		setType(std::string const type);

};

#endif