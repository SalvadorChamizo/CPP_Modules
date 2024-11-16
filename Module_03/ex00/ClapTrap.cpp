/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:05:37 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/16 17:17:04 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

ClapTrap::ClapTrap() : _name("Paco"), _hit_points(10), _energy(10), _damage(0)
{
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : ClapTrap()
{
    std::cout << "String constructor called\n";
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy = other._energy;
	this->_damage = other._damage;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */
