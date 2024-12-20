/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:11:11 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:49:54 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal: Default constructor called\n";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal: String constructor called\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal: Copy constructor called\n";
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Animal: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	Animal::makeSound(void) const
{
	std::cout << this->_type << ": AAAAaaahhhh UUUUuuuggggghhh...\n";
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}