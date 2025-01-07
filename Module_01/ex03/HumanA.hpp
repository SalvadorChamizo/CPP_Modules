/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:39:43 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/25 12:40:00 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"


class	HumanA {

	private:

		std::string		_name;
		Weapon const	&_weapon;


	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	attack(void) const;
};

#endif
