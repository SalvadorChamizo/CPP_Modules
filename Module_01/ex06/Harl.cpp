/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:59:49 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 12:33:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Harl::Harl(void)
{
	std::cout << "Hello, I'm Harl 3000." << "\n\n";
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Bye, Harl 3000 is going to sleep." << "\n\n";
	return ;
}

/* ************************************************************************** */
/*                             Private functions                              */
/* ************************************************************************** */

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n";
	return ;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!\nIf you did, I wouldn´t be asking for more!" << "\n\n";
	return ;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << "\n\n";
	return ;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << "\n\n";
	return ;
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	functions funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int	i = 0;

	while (i < 4)
	{
		if (!levels[i].compare(level))
		{
			break ;
		}
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*funcs[0])();
			// Fall through
		case 1:
			(this->*funcs[1])();
			// Fall through
		case 2:
			(this->*funcs[2])();
			// Fall through
		case 3:
			(this->*funcs[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n\n";
			break ;
	}
	return ;
}
