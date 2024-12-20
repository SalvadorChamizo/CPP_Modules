/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:40:11 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/10 18:01:42 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

void	mainWithVector(void)
{
	std::vector<int> mstack;

	std::cout << "\nTest Main with Vector\n\n";
	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::vector<int>::iterator it = mstack.begin();
	std::vector<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	//std::stack<int> s(mstack);
}

void	mainWithList(void)
{
	std::list<int> mstack;

	std::cout << "\nTest Main with List\n\n";
	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	//std::stack<int> s(mstack);
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	const MutantStack<int> c_mstack(mstack);
	MutantStack<int>::c_iterator it2 = c_mstack.cbegin();
	MutantStack<int>::c_iterator ite2 = c_mstack.cend();
	std::cout << "\nTest with const MutantStack\n\n";
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nTest with MutantStack\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "\nTest with Reverse Iterator\n\n";
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack<int> s(mstack);
	mainWithList();
	mainWithVector();
	return 0;
}