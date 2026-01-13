/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:39:51 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/21 15:47:19 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB : public Weapon {

	private:

		std::string const	_name;
		Weapon		*_weapon;


	public:

		HumanB(std::string const name);
		~HumanB(void);

		void	setWeapon(Weapon &weapon);
		void	attack(void) const;
};


#endif