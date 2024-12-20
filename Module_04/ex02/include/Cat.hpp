/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:50:37 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/21 19:26:32 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {

	private:
		Brain *brain;

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		~Cat();

		Cat &operator=(const Cat &other);

		virtual void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif