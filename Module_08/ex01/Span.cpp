/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:14 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/21 12:13:07 by schamizo         ###   ########.fr       */
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

	std::vector<int> diff(this->_vector.size());
	std::vector<int> copy(this->_vector);

	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), diff.begin());
	i = std::min_element(diff.begin() + 1, diff.end());
	return (*i);
}

int		Span::longestSpan(void)
{
	std::vector<int>::iterator	max;
	std::vector<int>::iterator	min;

	if (this->_vector.size() == 0 || this->_vector.size() == 1)
		throw Span::VectorTooSmall();
	max = std::max_element(this->_vector.begin(), this->_vector.end());
	min = std::min_element(this->_vector.begin(), this->_vector.end());
	return (*max - *min);
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
