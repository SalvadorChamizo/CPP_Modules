/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:32:44 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/22 19:09:22 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>
# include <iostream>

class	ICharacter;

class	AMateria {

	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &other);

		std::string const &getType(void) const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif