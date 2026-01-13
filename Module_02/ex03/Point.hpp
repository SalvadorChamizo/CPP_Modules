/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:28:27 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/16 16:07:01 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

	private:
		const Fixed	x;
		const Fixed y;
	
	public:
		Point();
		Point(const float num1, const float num2);
		Point(const Point &other);
		~Point();

		Point &operator=(const Point &other);

		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;
};

float	two_point_distance(Point &a, Point &b);
bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#endif