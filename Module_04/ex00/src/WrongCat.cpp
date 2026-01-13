/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:22:48 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:25:51 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat: Default constructor called\n";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat: String constructor called\n";
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	std::cout << "WrongCat: Copy constructor called\n";
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << ": Miiaaaaauuuuu miaaaauuuuu...\n";
}

std::string	WrongCat::getType(void) const
{
	return (this->_type);
}