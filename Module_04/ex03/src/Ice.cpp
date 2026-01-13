/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:02:56 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:56:02 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called.\n";
}

Ice::Ice(const Ice &other) : AMateria()
{
	std::cout << "Ice copy constructor called.\n";
	*this = other;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called.\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice copy operator overload called.\n";
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

AMateria *Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}