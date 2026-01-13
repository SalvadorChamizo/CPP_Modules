/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:54:31 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/18 12:45:26 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : _a(NULL), _size(0)
{
	std::cout << "Array: Default constructor called.\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : _a(NULL), _size(n)
{
	std::cout << "Array: Memory Allocation constructor called.\n";
	if (n == 0)
		throw std::out_of_range("Invalid size\n");
	if (n > 0)
	{
		this->_a = new T[n]();
	}
}

template <typename T>
Array<T>::Array(const Array &other) : _a(NULL), _size(0)
{
	std::cout << "Array: Copy constructor called.\n";
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array: Destructor called.\n";
	if (this->_size > 0)
		delete [] this->_a;
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);

	if (this->_size > 0)
	{
		if (this->_a != NULL)
		{
			delete [] this->_a;
		}
	}

	this->_size = other._size;
	if (this->_size > 0)
	{
		this->_a = new T[this->_size];
	
		for (size_t i = 0; i < this->_size; i++)
			this->_a[i] = other._a[i];
	}
	else
		this->_a = NULL;

	return (*this);
}

template <typename T>
T		&Array<T>::operator[](int index)
{
	if (index < 0 || index >= this->size())
		throw std::out_of_range("Index is out of bounds");
	return (this->_a[index]);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

template <typename T>
int	Array<T>::size(void)
{
	return (this->_size);
}

#endif