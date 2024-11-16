/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:22:50 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/08 15:56:20 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact_Class.hpp"
#include "../include/PhoneBook_Class.hpp"

void	terminal_clear(void)
{
    std::system("clear");
	std::cout << "\033[H\033[2J\033[3J" << RESET;
}

void	display_selection_menu(void)
{
	std::cout << "Select one of the following options:" RESET << std::endl;
	std::cout << MAGENTA "Add Contact: \"" RESET << "ADD";
	std::cout << MAGENTA "\" - Search: \"" RESET << "SEARCH";
	std::cout << MAGENTA "\" - Exit: \"" RESET << "EXIT" << MAGENTA "\"." RESET << std::endl;
	std::cout << std::endl;
}

void	sleep_one_second(void)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void	eof_handle(void)
{
	if (std::cin.eof())
	{
		std::cout <<std::endl;
		std::cout << RED "EOF detected. Exiting..." RESET <<std::endl;
		sleep_one_second();
		std::cout << YELLOW "Thanks for using the program."  RESET <<std::endl;
		std::cout <<std::endl;
		std::exit(0);
	}
}