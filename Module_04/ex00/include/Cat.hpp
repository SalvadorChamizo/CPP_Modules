/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:06:30 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/21 19:23:47 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal {

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		~Cat();

		Cat &operator=(const Cat &other);

		virtual void	makeSound(void) const;
};

#endif