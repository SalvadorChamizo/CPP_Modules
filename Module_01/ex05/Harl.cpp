/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:31:35 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 12:17:46 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Harl::Harl(void)
{
	std::cout << "Hello, I'm Harl 3000." << "\n";
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Bye, Harl 3000 is going to sleep." << "\n";
	return ;
}

/* ************************************************************************** */
/*                             Private functions                              */
/* ************************************************************************** */

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << "\n";
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn´t be asking for more!" << "\n";
	return ;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << "\n";
	return ;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << "\n";
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
			(this->*funcs[i])();
			return ;
		}
		i++;
	}
	std::cout << "Invalid comment: " << level << "." << "\n";
	return ;
}
