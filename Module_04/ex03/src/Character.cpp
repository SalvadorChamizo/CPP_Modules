/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:44:17 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:55:51 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Character::Character() : _name("")
{
	std::cout << "Character default constructor called.\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	std::cout << "Character constructor called.\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called.\n";
	*this = other;
}

Character::~Character()
{
	std::cout << "Character destructor called.\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Character &Character::operator=(const Character &other)
{
	std::cout << "Character copy operator overload called.\n";
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = other._inventory[i];
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *materia)
{
	int	i = 0;
	while (i < 4)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			break ;
		}
		i++;
	}
	if (i == 3)
		std::cout << "The inventory is full of materias. Please unequip one of them.\n";
	else
	{
		std::cout << "One materia has been equiped in slot " << i << ".\n";
		//this->_inventory[i] = materia;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Unequip: Invalid index.\n";
		return ;
	}
	if (!this->_inventory[idx])
		std::cout << "There isn't materia in slot " << idx << ".\n";
	else
	{
		std::cout << "Materia in slot " << idx << " has been unequiped.\n";
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Use: Invalid index.\n";
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Empty slot at index " << idx << ".\n";
}