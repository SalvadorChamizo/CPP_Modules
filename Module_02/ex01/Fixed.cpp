/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:19:12 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 17:20:35 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Fixed::Fixed(void) : fixed_point(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int param) : fixed_point(param << fract_bits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num) 
	: fixed_point(static_cast<int>(roundf(num * (1 << fract_bits))))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

/* ************************************************************************** */
/*            Copy assignment & Insertion operators overload                  */
/* ************************************************************************** */

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &fixed)
		return (*this);
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

int		Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	this->fixed_point = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point) / (1 << fract_bits));
}

int		Fixed::toInt(void) const
{
	return (fixed_point >> fract_bits);
}
