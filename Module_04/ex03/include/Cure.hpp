/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:38:52 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/22 19:48:17 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure &other);
		virtual ~Cure();

		Cure &operator=(const Cure &other);

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif