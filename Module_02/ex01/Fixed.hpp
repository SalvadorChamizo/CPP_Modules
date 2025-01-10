/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:19:28 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:54 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {

	private:
		int					fixed_point;
		static const int	fract_bits = 8;
	
	public:
		Fixed();
		Fixed(const int param);
		Fixed(const float num);
		Fixed(const Fixed &fixed);
		~Fixed();

		Fixed& operator=(const Fixed &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif