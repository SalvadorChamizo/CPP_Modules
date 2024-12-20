/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:24:30 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/06 18:43:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

static Base	*generate(void)
{
	int randomNumber = std::rand() % 3;
	if (randomNumber == 0)
		return (new A());
	else if (randomNumber == 1)
		return (new B());
	else
		return (new C());
}

static void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))  //dynamic_cast returns nullptr if the cast fails
		std::cout << "Type: A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "Type: B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "Type: C\n";
	else
		std::cout << "Unknown Type\n";
}

static void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p); //With references, dynamic_cast returns the std::bad_cast exception
		std::cout << "Type: A\n";
		(void)a;
	}
	catch (std::bad_cast&)
	{
		try
		{
			B	&b = dynamic_cast<B &>(p);
			std::cout << "Type: B\n";
			(void)b;
		}
		catch (std::bad_cast&)
		{
			try
			{
				C	&c = dynamic_cast<C &>(p);
				std::cout << "Type: C\n";
				(void)c;
			}
			catch (std::bad_cast&)
			{
				std::cout << "Unknown type\n";
			}
		}
	}
}

int	main(void)
{
	Base	*one;
	Base	*two;
	Base	*three;

	std::srand(static_cast<unsigned int>(time(0)));

	one = generate();
	two = generate();
	three = generate();

	std::cout << "By pointer:\n\n";

	identify(one);
	identify(two);
	identify(three);

	std::cout << "\nBy reference:\n\n";

	identify(*one);
	identify(*two);
	identify(*three);
}