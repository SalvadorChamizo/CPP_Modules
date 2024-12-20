/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:14 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/10 15:32:34 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Span::Span() : _size(1)
{
	std::cout << "Span: Default constructor called\n";
} 

Span::Span(unsigned int N) :  _size(N)
{
	std::cout << "Span: Constructor called\n";
}

Span::Span(const Span &other)
{
	std::cout << "Span: Copy constructor called\n";
	*this = other;
}

Span::~Span()
{
	std::cout << "Span: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Span	&Span::operator=(const Span &other)
{
	std::cout << "Span: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	this->_vector = other._vector;
	this->_size = other._size;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	Span::addNumber(int number)
{
	if (this->_vector.size() < this->getSize())
	{
		this->_vector.push_back(number);
	}
	else
	{
		throw std::out_of_range("Span: Out of range exception");
	}
}

int		Span::shortestSpan(void)
{
	std::vector<int>::iterator	i;

	if (this->_vector.size() == 0 || this->_vector.size() == 1)
		throw Span::VectorTooSmall();
	i = std::min_element(this->_vector.begin(), this->_vector.end());
	return (*i);
}

int		Span::longestSpan(void)
{
	std::vector<int>::iterator	i;

	if (this->_vector.size() == 0 || this->_vector.size() == 1)
		throw Span::VectorTooSmall();
	i = std::max_element(this->_vector.begin(), this->_vector.end());
	return (*i);
}

const char	*Span::VectorTooSmall::what(void) const throw()
{
	return ("Span: Vector too small to search for shortest or longest.\n");
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

unsigned int	Span::getSize(void) const
{
	return (this->_size);
}
