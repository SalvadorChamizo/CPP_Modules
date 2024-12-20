/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:22:28 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:25:20 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat: Default constructor called\n";
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat: String constructor called\n";
    this->_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "Cat: Copy constructor called\n";
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": Miiaaaaauuuuu miaaaauuuuu...\n";
}
