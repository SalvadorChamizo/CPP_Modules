/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:39:47 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/21 15:46:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

HumanB::HumanB(std::string const name) : _name(name),
										_weapon(NULL)
{
	std::cout << this->_name << " enters the battle." << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " leave the battle." << std::endl;
}

/* ************************************************************************** */
/*                             Private functions                              */
/* ************************************************************************** */


/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}

void    HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType();
    std::cout << std::endl;
    return ;
}