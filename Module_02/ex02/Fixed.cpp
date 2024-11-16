/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:42:32 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 19:24:41 by schamizo         ###   ########.fr       */
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
/*                            Operators overload                              */
/* ************************************************************************** */

/* Copy assignment operator */

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &fixed)
		return (*this);
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

/* Insertion operator */

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

/* Comparison operators */

bool	operator==(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point == fixed2.fixed_point);
}

bool	operator!=(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point != fixed2.fixed_point);
}

bool	operator<(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point < fixed2.fixed_point);
}

bool	operator>(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point > fixed2.fixed_point);
}

bool	operator<=(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point <= fixed2.fixed_point);
}

bool	operator>=(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point >= fixed2.fixed_point);
}

/* Arithmetic operator */

Fixed	operator+(const Fixed &fixed1, const Fixed &fixed2)
{
	return (Fixed(fixed1.toFloat() + fixed2.toFloat()));
}

Fixed	operator-(const Fixed &fixed1, const Fixed &fixed2)
{
	return (Fixed(fixed1.toFloat() - fixed2.toFloat()));
}

Fixed	operator*(const Fixed &fixed1, const Fixed &fixed2)
{
	return (Fixed(fixed1.toFloat() * fixed2.toFloat()));
}

Fixed	operator/(const Fixed &fixed1, const Fixed &fixed2)
{
	return (Fixed(fixed1.toFloat() / fixed2.toFloat()));
}

/* Increment/Decrement operators */

Fixed	&Fixed::operator++(void)
{
	++fixed_point;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--fixed_point;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
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

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.fixed_point < fixed2.fixed_point ? fixed1 : fixed2);
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.fixed_point > fixed2.fixed_point ? fixed1 : fixed2);
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point < fixed2.fixed_point ? fixed1 : fixed2);
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point > fixed2.fixed_point ? fixed1 : fixed2);
}