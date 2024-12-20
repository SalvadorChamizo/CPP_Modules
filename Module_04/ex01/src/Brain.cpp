/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:05:27 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:29:14 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Brain::Brain()
{
	std::cout << "Brain: Default constructor called\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain: Copy constructor called\n";
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Brain: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return (*this);
    for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

std::string Brain::getIdea(unsigned int index) const
{
	if (index >= 100)
	{
		std::cout << "Invalid index. Max index is 99.\n";
		return ("");
	}
	return (this->ideas[index]);
}

void	Brain::setIdea(std::string idea, unsigned int index)
{
	if (index >= 100)
	{
		std::cout << "Invalid index. Max index is 99\n";
		return ;
	}
	this->ideas[index] = idea;
	return ;
}