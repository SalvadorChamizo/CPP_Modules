/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:45:44 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/07 14:50:26 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include "Data.hpp"

class	Serializer {

	private:
		Serializer();
		Serializer(const Serializer &other);
		~ Serializer();

		Serializer	&operator=(const Serializer &other);
		
	public:
		static unsigned long	serialize(Data *ptr);
		static Data			*deserialize(unsigned long raw);

};

#endif