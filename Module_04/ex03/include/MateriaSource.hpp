/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:24:14 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/22 18:04:10 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {

	private:
		AMateria *_materias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		virtual	~MateriaSource();

		MateriaSource &operator=(const MateriaSource &other);

		virtual void	learnMateria(AMateria *materia);
		virtual AMateria *createMateria(std::string const &type);
};

#endif