/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:22:38 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:25:26 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog: Default constructor called\n";
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog: String constructor called\n";
    this->_type = "Cat";
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "Dog: Copy constructor called\n";
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Dog: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": Woooouff Wouffff...\n";
}
