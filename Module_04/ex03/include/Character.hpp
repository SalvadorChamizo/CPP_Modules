/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:10:24 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/22 19:12:28 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter {

	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		~Character();

		Character &operator=(const Character &other);

		std::string const &getName(void) const;
		virtual void	equip(AMateria *materia);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
};

#endif