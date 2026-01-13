/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:35:34 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/25 17:13:35 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <sstream>
# include <string>
# include <sys/time.h>
# include <cstdlib>
# include <iterator>
# include <list>
# include <deque>
# include <limits>

template <typename Container>
void	printTime(Container &container, int flag, std::string name);

template <typename Container>
Container mergeInsertionSort(Container &elements);

template <typename Container>
void insertUsingBinarySearch(Container& mainChain, const Container& indexList, const Container& numbersToInsert);

template <typename Container>
Container generateIndexInsertionList(Container &js_lst, Container &pend);

template <typename Container>
Container	generateJacobsthalSequence(Container &cont);

void	recursivePairsSort(std::vector<std::pair<int, int> > &pairs, int n);

#endif