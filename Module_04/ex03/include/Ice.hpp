/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:50:48 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/22 19:47:39 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice &other);
		virtual ~Ice();

		Ice &operator=(const Ice &other);

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif