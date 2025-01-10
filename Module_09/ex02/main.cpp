/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:07:48 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/08 15:41:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <string>
#include <sys/time.h>
#include <cstdlib>
#include <iterator>
#include <list>
#include <deque>

void	recursivePairsSort(std::vector<std::pair<int, int> > &pairs, int n)
{
	if (n <= 1)
		return ;

	recursivePairsSort(pairs, n - 1);

	std::pair<int, int> last = pairs[n - 1];
	int	j = n - 2;

	while (j >= 0 && pairs[j].first > last.first)
	{
		pairs[j + 1] = pairs[j];
		j--;
	}
	pairs[j + 1] = last;
}

static size_t	jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	size_t	prev1 = 1;
	size_t	prev2 = 0;
	size_t	current = 0;

	for (size_t i = 2; i <= n; ++i)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return (current);
}

template <typename Container>
Container	generateJacobsthalSequence(Container &cont)
{
	Container sequence;
	size_t jacobIndex = 3;
	size_t currentValue;

	if (cont.size() == 2)
	{
		sequence.push_back(1);
		return (sequence);
	}
	while ((currentValue = jacobsthal(jacobIndex)) < cont.size())
	{
		sequence.push_back(currentValue);
		++jacobIndex;
	}
	return (sequence);
}

template <typename Container>
Container generateIndexInsertionList(Container &js_lst, Container &pend)
{
	Container			final_sequence;
	typename Container::iterator	js_iter = js_lst.begin();

	int	last_js = 0;

	// Base case with one jacobsthal number
	if (js_lst.size() == 1)
	{
		if (*js_iter == 1)
		{
			final_sequence.push_back(1);
			return (final_sequence);
		}
		if (pend.size() == 4)
		{
			final_sequence.push_back(3);
		}
		final_sequence.push_back(2);
		final_sequence.push_back(1);
		int current_js = *js_iter;
		typename Container::iterator next_iter = js_iter;
		++next_iter;
		if (next_iter == js_lst.end())
		{
			for (size_t i = current_js + 1; i <= pend.size(); ++i) // Remaining indexes
				final_sequence.push_back(i);
		}
		return (final_sequence);
	}
	while (js_iter != js_lst.end())
	{
		int current_js = *js_iter;

		// Add the current Jacobsthal number to the sequence
		final_sequence.push_back(current_js);

		// Add intermediate numbers for the first jacobsthal (works slighly different)
		if (js_iter == js_lst.begin())
		{
			for (int i = current_js - 1; i > last_js; --i)
				final_sequence.push_back(i);
			last_js = current_js - 1;
		}

		// Add the intermediate numbers in descending order
		for (int i = current_js - 1; i > last_js + 1; --i)
			final_sequence.push_back(i);

		last_js = current_js - 1;

		// Handle the last Jacobsthal number separately
		typename Container::iterator next_iter = js_iter;
		++next_iter;
		if (next_iter == js_lst.end())
		{
			for (int i = current_js - 1; i > last_js; --i) // Numbers before the last Jacobstal number
				final_sequence.push_back(i);
			for (int i = current_js + 1; i < static_cast<int>(pend.size()); ++i) // Remaining indexes
				final_sequence.push_back(i);
		}

		++js_iter;
	}
	return (final_sequence);
}

template <typename Container>
void insertUsingBinarySearch(Container& mainChain, const Container& indexList, const Container& numbersToInsert)
{
	typename Container::const_iterator indexIter = indexList.begin();

	while (indexIter != indexList.end())
	{
		int	index = *indexIter;
		typename Container::const_iterator numIter = numbersToInsert.begin();
		std::advance(numIter, index);

		typename Container::iterator insertPosition = std::lower_bound(mainChain.begin(), mainChain.end(), *numIter);
		mainChain.insert(insertPosition, *numIter);

		++indexIter;
	}
}

template <typename Container>
Container mergeInsertionSort(Container &elements)
{

	/* Step 1: Group the elements of "elements" into [n/2] pairs of elements */
	if (elements.size() <= 1)
	{
		return elements;
	}

	int odd = -1; // If the number of elements is odd, save the last number for later
	if (elements.size() % 2 != 0)
	{
		odd = elements.back();
		elements.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	typename Container::const_iterator it = elements.begin();
	while (it != elements.end())
	{
		typename Container::const_iterator next = it;
		++next;

		/* Step 2: Determine the larger of the two elements in each pair */
		if (next != elements.end())
		{
			if (*it > *next)
			{
				pairs.push_back(std::make_pair(*it, *next));
			}
			else
			{
				pairs.push_back(std::make_pair(*next, *it));
			}
			it = next; // Advance the iterator to skip the paired element
		}
		++it; // Move to the next element
	}

	/* Step 3: Recursively sort the [n/2] larger elements in each pair */
	recursivePairsSort(pairs, pairs.size());

	/* Step 4: Create the main chain and pend */
	Container main_chain;
	Container pend;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		main_chain.push_back(it->first);
		pend.push_back(it->second);
	}
	main_chain.insert(main_chain.begin(), pend.front());

	/* Step 5: Generate the order of insertion using the jacobsthal sequence */
	Container	jacobsthalSequence = generateJacobsthalSequence(pend);

	Container	insertionList = generateIndexInsertionList(jacobsthalSequence, pend);

	/* Step 6: Insert the elements of the pend into the main chain using binary search to determine the position of each element */
	insertUsingBinarySearch(main_chain, insertionList, pend);

	/* Step 7: Insert the odd number */
	if (odd != -1)
	{
		typename Container::iterator insertPosition = std::lower_bound(main_chain.begin(), main_chain.end(), odd);
		main_chain.insert(insertPosition, odd);
	}

	return (main_chain);
}

template <typename Container>
void	printTime(Container &container, int flag, std::string name)
{
	struct timeval start, end;
	Container sorted;

	gettimeofday(&start, NULL);

	sorted = mergeInsertionSort(container);
		
	gettimeofday(&end, NULL);

	if (flag == 1)
	{
		std::cout << "After: ";
		for (typename Container::iterator it = sorted.begin(); it != sorted.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << "\n\n";
	}
	long seconds = (end.tv_sec - start.tv_sec) * 1000000.0;
	long microseconds = end.tv_usec - start.tv_usec;
	long time = seconds + microseconds;
	std::cout << "Time to process a range of " << container.size() << " elements with std::" << name << ": " << time << " us\n";
}

int	main(int argc, char **argv)
{
	std::vector<int> vector;
	std::list<int> list;
	std::deque<int> deque;
	int	nb;

	try
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j] != '\0'; j++)
			{
				if (!isdigit(argv[i][j]) && argv[i][j] != '+' && argv[i][j] != '-')
					throw std::invalid_argument("Invalid character.\n");
			}
			nb = atoi(argv[i]);
			if (nb < 0)
				throw std::invalid_argument("Numbers must be positive.\n");
			vector.push_back(nb);
			list.push_back(nb);
			deque.push_back(nb);
		}

		std::cout << "Before: ";
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << "\n";
		printTime(vector, 1, "vector");
		printTime(list, 0, "list");
		printTime(deque, 0, "deque");
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what();
		return (1);
	}
}