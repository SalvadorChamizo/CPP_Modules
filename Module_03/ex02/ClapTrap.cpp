/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:41 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/19 17:32:06 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

ClapTrap::ClapTrap() : _name("Paco"), _hit_points(100), _energy(50), _damage(20)
{
	std::cout << "ClapTrap: Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(100), _energy(50), _damage(20)
{
	std::cout << "ClapTrap: String constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap: Copy constructor called\n";
	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: Destructor called\n";
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

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enought hit points. It's completely destroyed.\n";
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enought energy to attack.\n";
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!\n";
		this->_energy--;
		return ;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already destroyed. This attack would do nothing.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points - amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		std::cout << "ClapTrap " << this->_name << " has been attacked with " << amount << " points of damage! ";
		std::cout << "Now it has " << this->_hit_points << " hit points left.\n";
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enought hit points. It's completely destroyed.\n";
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enought energy to repair itself.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points + amount;
		std::cout << "ClapTrap " << this->_name << " is repairing itself " << amount << " hit points. ";
		std::cout << "Now it has " << this->_hit_points << " hit points.\n";
		this->_energy--;
		return ;
	}
}

int	ClapTrap::getDamage(void)
{
	return (this->_damage);
}

void	ClapTrap::setDamage(unsigned int damage)
{
	std::cout << "ClapTrap " << this->_name << " has a new weapon! ";
	std::cout << "Now it has " << damage << " attack damage.\n";
	this->_damage = damage;
}