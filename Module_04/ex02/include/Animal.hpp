/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:50:21 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/22 13:00:12 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal {

	protected:
		std::string	_type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &other);

		virtual void	makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif