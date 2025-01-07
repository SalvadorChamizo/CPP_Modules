/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:34:35 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/26 19:18:40 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() 
{
	int	scavtrapEnergy = 50;

	std::cout << "DiamondTrap: Default constructor called\n";
	this->_energy = scavtrapEnergy;
}

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), 
	ScavTrap(name + "_scav_name"),
	FragTrap(name + "_flag_name"),
	_name(name)
{
	int	scavtrapEnergy = 50;

	std::cout << "DiamondTrap: String constructor called\n";
	this->_energy = scavtrapEnergy;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap: Copy constructor called\n";
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
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

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name << " says: Who am I??? " << this->_name << ", " << ClapTrap::_name << " or a monster...\n";
	return ;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	std::cout << this->_hit_points << std::endl;
	std::cout << this->_energy << std::endl;
	std::cout << this->_damage << std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " is already destroyed. This attack would do nothing.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points - amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		std::cout << "DiamondTrap " << this->_name << " has been attacked with " << amount << " points of damage! ";
		std::cout << "Now it has " << this->_hit_points << " hit points left.\n";
		return ;
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " doesn't have enought hit points. It's completely destroyed.\n";
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " doesn't have enought energy to repair itself.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points + amount;
		std::cout << "DiamondTrap " << this->_name << " is repairing itself " << amount << " hit points. ";
		std::cout << "Now it has " << this->_hit_points << " hit points.\n";
		this->_energy--;
		return ;
	}
}

int	DiamondTrap::getDamage(void)
{
	return (this->_damage);
}

void	DiamondTrap::setDamage(unsigned int damage)
{
	std::cout << "DiamondTrap " << this->_name << " has a new weapon! ";
	std::cout << "Now it has " << damage << " attack damage.\n";
	this->_damage = damage;
}
