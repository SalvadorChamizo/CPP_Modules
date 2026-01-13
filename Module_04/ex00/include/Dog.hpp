/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:10:07 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/21 19:23:53 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class	Dog : public Animal {

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);

		virtual void	makeSound(void) const;
};

#endif