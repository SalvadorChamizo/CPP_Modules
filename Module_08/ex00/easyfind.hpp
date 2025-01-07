/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:24:28 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/07 15:02:41 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

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

