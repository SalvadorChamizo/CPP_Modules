/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:42:31 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 15:05:57 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	private:
		int					fixed_point;
		static const int	fract_bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		~Fixed();

		Fixed &operator=(const Fixed& fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif