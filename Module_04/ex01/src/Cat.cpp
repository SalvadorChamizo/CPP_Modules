/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:50:29 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:29:21 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat: Default constructor called\n";
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat: String constructor called\n";
    this->_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "Cat: Copy constructor called\n";
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor called\n";
	delete this->brain;
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	if (this->brain != NULL)
		delete (this->brain);
	this->brain = new Brain(*other.brain);
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": Miiaaaaauuuuu miaaaauuuuu...\n";
}

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}