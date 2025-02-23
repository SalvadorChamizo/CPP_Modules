/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:44 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/20 15:33:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <vector>

template <typename T>
class	MutantStack : public std::stack<T> {
	private:
	public:
		MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T>(other) {};
		~MutantStack() {};

		MutantStack	&operator=(const MutantStack &other) {std::stack<T>::operator=(other); return (*this);};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator c_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator c_reverse_iterator;
		
		iterator begin() {
			return (this->c.begin());
		}

		iterator end() {
			return (this->c.end());
		}

		c_iterator cbegin() const {
			return (this->c.begin());
		}

		c_iterator cend() const {
			return (this->c.end());
		}

		reverse_iterator	rbegin() {
			return (this->c.rbegin());
		}

		reverse_iterator	rend() {
			return (this->c.rend());
		}

		c_reverse_iterator	crbegin() const {
			return (this->c.rbegin());
		}

		c_reverse_iterator	crend() const {
			return (this->c.rend());
		}
};

#endif