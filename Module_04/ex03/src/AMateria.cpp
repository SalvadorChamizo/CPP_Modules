/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:32:44 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:55:42 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

AMateria::AMateria() : _type("")
{
	std::cout << "AMateria default constructor called.\n";
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria constructor called.\n";
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor called.\n";
	*this = other;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called.\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy operator overload called.\n";
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	(void) target;
}