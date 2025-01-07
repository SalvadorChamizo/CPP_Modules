/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:42 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/07 14:50:19 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Serializer::Serializer()
{
	std::cout << "Serializer: Default constructor called\n";
} 

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Serializer: Copy constructor called\n";
	*this = other;
}

Serializer::~Serializer()
{
	std::cout << "Serializer: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Serializer	&Serializer::operator=(const Serializer &other)
{
	std::cout << "Serializer: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

unsigned long	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<unsigned long>(ptr));
}

Data		*Serializer::deserialize(unsigned long raw)
{
	return (reinterpret_cast<Data *>(raw));
}
