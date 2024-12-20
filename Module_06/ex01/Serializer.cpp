/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:42 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/06 16:09:34 by schamizo         ###   ########.fr       */
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

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
