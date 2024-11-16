/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:22:40 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 18:53:45 by schamizo         ###   ########.fr       */
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
		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

		friend	bool operator==(const Fixed &fixed1, const Fixed &fixed2);
		friend	bool operator!=(const Fixed &fixed1, const Fixed &fixed2);

		friend	bool operator<(const Fixed &fixed1, const Fixed &fixed2);
		friend	bool operator>(const Fixed &fixed1, const Fixed &fixed2);

		friend	bool operator<=(const Fixed &fixed1, const Fixed &fixed2);
		friend	bool operator>=(const Fixed &fixed1, const Fixed &fixed2);

		friend Fixed operator+(const Fixed &fixed1, const Fixed &fixed2);
		friend Fixed operator-(const Fixed &fixed1, const Fixed &fixed2);
		friend Fixed operator*(const Fixed &fixed1, const Fixed &fixed2);
		friend Fixed operator/(const Fixed &fixed1, const Fixed &fixed2);

		Fixed& operator++(void);
		Fixed& operator--(void);

		Fixed operator++(int);
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &min(Fixed& num1, Fixed& num2);
		static const Fixed &min(const Fixed& num1, const Fixed& num2);
		static Fixed &max(Fixed& num1, Fixed& num2);
		static const Fixed &max(const Fixed& num1, const Fixed& num2);
};

#endif