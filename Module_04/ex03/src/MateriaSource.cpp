/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:41 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/28 14:59:18 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called.\n";
	for	(int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called.\n";
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called.\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy operator overload called.\n";
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete _materias[i];
		this->_materias[i] = other._materias[i];
	}
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia;
			return ;
		}
	}
	delete materia;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 3; i >= 0; i--)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}
