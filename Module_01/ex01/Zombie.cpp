/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:41:16 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/17 17:28:17 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name) : _name(name)
{

}

Zombie::~Zombie()
{
    std::cout << this->_getName() << " is destroyed." << std::endl;
	return ;
}

/* ************************************************************************** */
/*                             Private functions                              */
/* ************************************************************************** */

std::string	Zombie::_getName(void)
{
	return (this->_name);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}