/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:20:59 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/22 19:02:00 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "ICharacter.hpp"

class	IMateriaSource {

	public:
		virtual	~IMateriaSource() {}
		virtual void	learnMateria(AMateria*) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif