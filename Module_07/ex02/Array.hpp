/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:01:23 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/18 11:40:59 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <limits.h>
# include <iostream>

template <typename T>
class	Array {
	private:
		T				*_a;
		size_t	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();

		Array	&operator=(const Array &other);
		T		&operator[](int index);

		int	size(void);
};

#endif