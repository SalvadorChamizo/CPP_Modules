/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:54 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/20 15:51:55 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCat_HPP
# define WRONGCat_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

	protected:
		std::string	_type;

	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &other);
		~WrongCat();

		WrongCat &operator=(const WrongCat &other);

		void	makeSound(void) const;
		std::string getType(void) const;
};

#endif