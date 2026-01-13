/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:43:32 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/21 11:59:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>

class	Span {
	private:
		std::vector<int> 	_vector;
		unsigned int		_size;
	
		Span();

	public:
		Span(unsigned int N);
		Span(const Span &other);
		~Span();

		Span			&operator=(const Span &other);

		unsigned int	getSize(void) const;

		void			addNumber(int number);

		int				shortestSpan(void);
		int				longestSpan(void);

		class	VectorTooSmall : std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

#endif