/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:19:06 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/15 18:31:05 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook_Class.hpp"
#include <iomanip>

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

PhoneBook::PhoneBook(void) : _index(-1)
{

}

PhoneBook::~PhoneBook(void)
{
	return ;
}

/* ************************************************************************** */

/* ************************************************************************** */
/*                             Private functions                              */
/* ************************************************************************** */

/*   General functions*/

int	PhoneBook::_increment_index(void)
{
	int	flag;
	if (_index >= 7)
	{
		std::cout << RED "PhoneBook is full. "; 
		std::cout << "The oldest contact will be overwrited." RESET << std::endl;
		std::cout << std::endl;
		std::cout << YELLOW "Do you want to continue? " GREEN "Yes: " RESET "1. " RED "No: " RESET "2." << std::endl;
		std::cout << std::endl;
		std::cin >> flag;
		if (flag == 2)
		{
			std::cout << ITALIC "Returning to the selection menu..." RESET << std::endl;
			sleep_one_second();
			return (1);
		}
		_index = 0;
	}
	else
	{
		_index++;
	}
	return (0);
}

/* ************************************************************************** */
/********                  Functions used by add method               *********/

std::string	PhoneBook::_add_contact_field(std::string str)
{
	std::string temp;

	temp = "";
	while (temp.empty())
	{
		std::cout << MAGENTA << str << RESET;
		std::getline(std::cin, temp);
		std::cout << std::endl;
		eof_handle();
		if (temp.empty())
			std::cout << RED "Input cannot be empty." RESET << std::endl;
	}		
	return (temp);
}

int	PhoneBook::_add_contact_field_nbr(std::string str)
{
	int			nbr;

	nbr = -1;
		while (nbr == -1)
		{
			std::cout << MAGENTA << str << RESET;
			std::cin >> nbr;
			std::cout << std::endl;
			if (error_handle())
			{
				nbr = -1;
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		};
	return (nbr);
}

/* ************************************************************************** */
/********                Functions used by search method              *********/

void	PhoneBook::_print_contact_string(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}


void	PhoneBook::_print_contact_table(int index)
{
	if (this->_contact_list[index].is_empty())
	{
		return ;
	}
	std::cout << "|" << std::setw(10) << index << "|";
	_print_contact_string(this->_contact_list[index].get_first_name());
	_print_contact_string(this->_contact_list[index].get_last_name());
	_print_contact_string(this->_contact_list[index].get_nickname());
	std::cout << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::_print_search_table(void)
{
	int	i;

	i = 0;
	std::cout << "+----------------" YELLOW "SEARCH MENU" RESET "----------------+" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   " YELLOW "INDEX  " RESET   "|" YELLOW "FIRST NAME" RESET;
	std::cout << "|" YELLOW " LAST NAME" RESET "|" YELLOW " NICKNAME " RESET "|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (i < 8)
	{
		_print_contact_table(i);
		i++;
	}
	std::cout << std::endl;
}

int		PhoneBook::_display_index(int index)
{
	if (index >= 0 && index <= 7)
	{
		if (this->_contact_list[index].display_contact_info())
			return (1);
		else
		{
			std::cout << RED "There is not contact at index " << index << "." RESET << std::endl;
			return (0);
		}
	}
	std::cout << RED "Invalid index." RESET << std::endl;
	return (0);
}

void	PhoneBook::_search_loop(void)
{
	int	input;

	while (input != 3)
	{
		std::cout << "Search Menu options: " << std::endl;
		std::cout << MAGENTA "Display some contact: \"" RESET << "1";
		std::cout << MAGENTA "\" - Exit the Search Menu: \"" RESET << "2";
		std::cout << MAGENTA "\" - Exit the program: \"" RESET << "3" << MAGENTA "\"." RESET << std::endl;
		std::cout << std::endl;
		std::cin >> input;
		if (error_handle())
		{
			this->_print_search_table();
			continue ;
		}
		std::cout << std::endl;
		if (input == 1)
		{
			std::cout << "Select an index to display: " << std::endl;
			std::cin >> input;
			terminal_clear();
			if (error_handle())
			{
				this->_print_search_table();
				continue ;
			}
			std::cout << std::endl;
			this->_display_index(input);
			std::cout << std::endl;
		}
		else if (input == 2)
		{
			std::cout << "Exiting the Search Menu..." << std::endl;
			std::cout << std::endl;
			sleep_one_second();
			terminal_clear();
			return ;
		}
		else if (input == 3)
		{
			this->exit_message();
			exit(0);
		}
	}
	return ;
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void	PhoneBook::add()
{
	std::string temp;
	int			nbr;

	temp = "";
	nbr = 0;
	if (_increment_index() == 1)
		return ;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << GREEN "Adding new contact:" RESET << std::endl;

	temp = _add_contact_field("Enter the first name: ");
	this->_contact_list[_index].set_first_name(temp);

	temp = _add_contact_field("Enter the last name: ");
	this->_contact_list[_index].set_last_name(temp);

	temp = _add_contact_field("Enter the nickname: ");
	this->_contact_list[_index].set_nickname(temp);

	nbr = _add_contact_field_nbr("Enter the phone number: ");
	this->_contact_list[_index].set_number(nbr);

	temp = _add_contact_field("Enter your darkest secret: ");
	this->_contact_list[_index].set_darkest_secret(temp);

	std::cout << GREEN "Contact added successfully!" RESET << std::endl;
	std::cout << std::endl;
	sleep_one_second();
}

void	PhoneBook::search()
{
	terminal_clear();
	if (_index == -1)
	{
		std::cout << std::endl;
		std::cout << RED "No contacts added to the PhoneBook. " RESET;
		std::cout << "Please ADD a contact first." << std::endl;
		std::cout << std::endl;
		return ;
	}
	this->_print_search_table();
	this->_search_loop();
	return ;
}

void	PhoneBook::exit_message()
{
	std::cout << ITALIC "Selling your personal data to China..." RESET <<std::endl;
	sleep_one_second();
	std::cout << YELLOW "Thanks for using the program."  RESET <<std::endl;
	std::cout << std::endl;
}
