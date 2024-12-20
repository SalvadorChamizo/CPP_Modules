/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:47 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/16 16:06:18 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	makeCalc(std::stack<int> &stack, std::string value)
{
	int	a;
	int	b;

	b = stack.top(); stack.pop();
	a = stack.top(); stack.pop();

	if (value[0] == '+')
	{
		stack.push(a + b);
	}
	else if (value[0] == '-')
	{
		stack.push(a - b);
	}
	else if (value[0] == '*')
	{
		stack.push(a * b);
	}
	else if (value[0] == '/')
	{
		if (b == 0)
			throw std::domain_error("Not possible to divide by zero.\n");
		stack.push(a / b);
	}
}

void	parseExpression(std::string line)
{
	std::stack<int> 	stack;
	std::istringstream	lineStream(line);
	std::string			value;

	while (getline(lineStream, value, ' '))
	{
		if (isdigit(value[0]) && value.size() == 1)
			stack.push(atoi(value.c_str()));
		else if ((value[0] == '*' || value[0] == '/' || value[0] == '+' || value[0] == '-') && value.size() == 1)
		{
			if (stack.size() < 2)
				throw std::invalid_argument("Invalid RPN expression.\n");
			makeCalc(stack, value);
		}
		else
		{
			throw std::invalid_argument("Invalid token in RPN expression.\n");
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Invalid RPN expression.\n");
	std::cout << stack.top() << "\n";
}

int	main(int argc, char **argv)
{
	std::string		line;
	std::stack<int> stack;

	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments.\n";
		return (1);
	}

	line = argv[1];
	try
	{
		parseExpression(line);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what();
		return (1);
	}
}