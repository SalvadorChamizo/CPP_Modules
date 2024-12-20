/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:24:28 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/13 11:39:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& x, int y)
{
	auto i = find(begin(x), end(x), y);
	if (i == end(x))
		return (i);
	return (i);
}

template <typename T>
typename T::const_iterator easyfind(const T &x, int y)
{
	auto i = find(begin(x), end(x), y);
	if (i == end(x))
		return (i);
	return (i);
}

