/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:20:59 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/13 11:47:02 by schamizo         ###   ########.fr       */
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
		std::cout << "Shortest number: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest number: " << sp.longestSpan() << std::endl;
		std::cout << "\n";
	}
	catch (std::out_of_range &e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	catch (Span::VectorTooSmall &e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
}

int main()
{
	std::srand(time(0));

	testSpanAnySize(10);
	testSpanAnySize(100);
	testSpanAnySize(1000);
	testSpanAnySize(10000);
	testSpanAnySize(100000);

    return (0);
}