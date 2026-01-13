/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:04:47 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/26 18:28:49 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: Default constructor called\n";
	this->_hit_points = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap: String constructor called\n";
	this->_hit_points = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	std::cout << "FragTrap: Copy constructor called\n";
	*this = other;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

FragTrap &FragTrap::operator=(const FragTrap &other)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " wants to high fives with everyone!\n";
	return ;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enought hit points. It's completely destroyed.\n";
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enought energy to attack.\n";
		return ;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!\n";
		this->_energy--;
		return ;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " is already destroyed. This attack would do nothing.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points - amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		std::cout << "FragTrap " << this->_name << " has been attacked with " << amount << " points of damage! ";
		std::cout << "Now it has " << this->_hit_points << " hit points left.\n";
		return ;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enought hit points. It's completely destroyed.\n";
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "FragTrap " << this->_name << " doesn't have enought energy to repair itself.\n";
		return ;
	}
	else
	{
		this->_hit_points = this->_hit_points + amount;
		std::cout << "FragTrap " << this->_name << " is repairing itself " << amount << " hit points. ";
		std::cout << "Now it has " << this->_hit_points << " hit points.\n";
		this->_energy--;
		return ;
	}
}

int	FragTrap::getDamage(void)
{
	return (this->_damage);
}

void	FragTrap::setDamage(unsigned int damage)
{
	std::cout << "FragTrap " << this->_name << " has a new weapon! ";
	std::cout << "Now it has " << damage << " attack damage.\n";
	this->_damage = damage;
}
