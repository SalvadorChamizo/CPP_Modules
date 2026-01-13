/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:56:16 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:55:57 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called.\n";
}

Cure::Cure(const Cure &other) : AMateria()
{
	std::cout << "Cure copy constructor called.\n";
	*this = other;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called.\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy operator overload called.\n";
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

AMateria *Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}