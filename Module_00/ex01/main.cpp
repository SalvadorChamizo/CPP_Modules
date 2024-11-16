/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:04:37 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/08 15:57:15 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Contact_Class.hpp"
#include "./include/PhoneBook_Class.hpp"
#include "./include/phonebook.hpp"

void	program_start(void)
{
	terminal_clear();
	std::cout << std::endl;
	std::cout << BLUE BOLD "Welcome to the Schamizo's PhoneBook app." RESET << std::endl;
	sleep_one_second();
	std::cout << std::endl;
}

int		error_handle(void)
{
	if (std::cin.fail())
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
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
		std::cout << RED << "Invalid input. Please enter a number." RESET << std::endl;
		std::cout << std::endl;
		return (1);
	}
	return (0);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command = "";

	program_start();
	while (command.compare("EXIT"))
	{
		display_selection_menu();
		std::cin >> command;
		if (error_handle() == 1)
			continue ;
		std::cout << std::endl;
		if (!command.compare("ADD"))
		{
			phonebook.add();
			error_handle();
			terminal_clear();
		}
		else if (!command.compare("SEARCH"))
		{
			std::cout << YELLOW "Opening search menú..." RESET << std::endl;
			sleep_one_second();
			phonebook.search();
		}
		else if (!command.compare("EXIT"))
		{
			phonebook.exit_message();
		}
		else
		{
			std::cout << RED "The command " << command << " is not a valid option." RESET << std::endl;
			std::cout << std::endl;
		}
	}
	return (0);
}
