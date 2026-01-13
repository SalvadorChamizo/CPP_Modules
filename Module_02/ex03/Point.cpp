/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:28:23 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/16 15:56:50 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float num1, const float num2) : x(num1), y(num2)
{
}

Point::Point(const Point &other)
{
	*this = other;
}

Point::~Point(void)
{
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Point &Point::operator=(const Point &other)
{
	if (this == &other)
		return (*this);
	(Fixed)this->x = other.x;
	(Fixed)this->y = other.y;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

const Fixed	&Point::getX(void) const
{
	return (this->x);
}

const Fixed	&Point::getY(void) const
{
	return (this->y);
}