/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:11 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/21 19:24:31 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {

	private:
		Brain *brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);

		virtual void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif