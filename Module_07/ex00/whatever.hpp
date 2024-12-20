/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:46:07 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/09 15:21:05 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &x, T &y)
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T	min(T x, T y)
{
	if (x == y)
		return (y);
	return ((x < y) ? x : y);
}

template <typename T>
T	max(T x, T y)
{
	if (x == y)
		return (y);
	return ((x > y) ? x : y);
}

#endif