/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:06:59 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/19 18:27:26 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap: Default constructor called\n";

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap: String constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap()
{
	std::cout << "ScavTrap: Copy constructor called\n";
	*this = other;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!\n";
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enought hit points. It's completely destroyed.\n";
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enought energy to attack.\n";
		return ;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!\n";
		this->_energy--;
		return ;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is already destroyed. This attack would do nothing.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points - amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		std::cout << "ScavTrap " << this->_name << " has been attacked with " << amount << " points of damage! ";
		std::cout << "Now it has " << this->_hit_points << " hit points left.\n";
		return ;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enought hit points. It's completely destroyed.\n";
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enought energy to repair itself.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points + amount;
		std::cout << "ScavTrap " << this->_name << " is repairing itself " << amount << " hit points. ";
		std::cout << "Now it has " << this->_hit_points << " hit points.\n";
		this->_energy--;
		return ;
	}
}

int	ScavTrap::getDamage(void)
{
	return (this->_damage);
}

void	ScavTrap::setDamage(unsigned int damage)
{
	std::cout << "ScavTrap " << this->_name << " has a new weapon! ";
	std::cout << "Now it has " << damage << " attack damage.\n";
	this->_damage = damage;
}
