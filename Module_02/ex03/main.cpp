/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:28:11 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/16 16:42:29 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	test(const Point &a, const Point &b, const Point &c, const Point &point, bool expected)
{
	bool	result = bsp(a, b, c, point);

	std::cout << "Expected: " << expected << ". Result: " << result << "\n";
}

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(20.0f, 0.0f);
	Point c(10.0f, 30.0f);

	Point insidePoint(10.0f, 15.0f);
	Point outsidePoint(30.0f, 15.0f);
	Point edgePoint(10.0f, 0.0f);
	Point vertexPoint(0.0f, 0.0f);

	std::cout << "insidePoint test:\n";
	test(a, b, c, insidePoint, true);
	std::cout << "outsidePoint test:\n";
	test(a, b, c, outsidePoint, false);
	std::cout << "edgePoint test:\n";
	test(a, b, c, edgePoint, false);
	std::cout << "vertexPoint test:\n";
	test(a, b, c, vertexPoint, false);
	return (0);
}