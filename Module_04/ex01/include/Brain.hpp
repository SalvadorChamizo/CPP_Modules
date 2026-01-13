/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:05:30 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/20 19:21:32 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain {

	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain	&operator=(const Brain &other);

		std::string getIdea(unsigned int index) const;
		void		setIdea(std::string idea, unsigned int index);

};

#endif