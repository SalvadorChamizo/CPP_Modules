/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:53:44 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/08 15:43:15 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/* This function call needs to specify the type received 
by the function passed by parameter. Example: "iter(array, 4, print<int>);" */

template <typename T, typename U>
void	iter(T *array, int len, U function)
{
	for (int i = 0; i < len; i++)
		function(array[i]);
}

/* Overloaded function to pass functions by parameter without specifiying
the type received by the function. Example: "iter(array, 4, print);" */

template <typename T>
void	iter(T *array, int len, void (*f)(T &element))
{
	for (int i = 0; i < len; i++)
		f(array[i]);
}

/* Templates to test the iter function */

template <typename T>
void	print(T &x)
{
	std::cout << x << "\n";
}

template <typename T>
void	sumOneToAll(T &x)
{
	x += 1;
}

#endif