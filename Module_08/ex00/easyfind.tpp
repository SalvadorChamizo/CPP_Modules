/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:52:34 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/20 15:00:13 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& x, int y)
{
	typename T::iterator i = find(x.begin(), x.end(), y);
	if (i == x.end())
		return (i);
	return (i);
}

template <typename T>
typename T::const_iterator easyfind(const T &x, int y)
{
	typename T::const_iterator i = find(x.begin(), x.end(), y);
	if (i == x.end())
		return (i);
	return (i);
} 
