/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:20:59 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/21 12:19:47 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void    testSpanAnySize(unsigned int N)
{
    Span	sp = Span(N);
	try
	{
		for (unsigned i = 0; i < N; i++)
			sp.addNumber(rand());

		std::cout << "\n";
		std::cout << "Given size: " << N << "\n";
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
}

int main()
{
	std::srand(time(0));

	Span sp = Span(5);

	sp.addNumber(20);
	sp.addNumber(18);
	sp.addNumber(1);
	sp.addNumber(5);
	sp.addNumber(10);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	testSpanAnySize(10);
	testSpanAnySize(100);
	testSpanAnySize(1000);
	testSpanAnySize(10000);
	testSpanAnySize(100000);

    return (0);
}