/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:22:37 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/15 18:06:01 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact_Class.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Contact::Contact(void) : _first_name(""),
						_last_name(""),
						_nickname(""),
						_phone_number(-1),
						_darkest_secret("")
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

/* ************************************************************************** */
/*                                   Getters                                 */
/* ************************************************************************** */

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string Contact::get_nickname(void)
{
	return (this->_nickname);
}

int			Contact::get_number(void)
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}

/* ************************************************************************** */
/*                                   Setters                                  */
/* ************************************************************************** */

void	Contact::set_first_name(std::string str)
{
	this->_first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::set_number(int nbr)
{
	this->_phone_number = nbr;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->_darkest_secret = str;
}

/* ************************************************************************** */
/*                             Private functions                              */
/* ************************************************************************** */

int		Contact::is_empty(void)
{
	if (this->_first_name.empty()
		|| this->_last_name.empty()
		|| this->_nickname.empty()
		|| this->_phone_number == -1
		|| this->_darkest_secret.empty())
		return (1);
	return (0);
}

int		Contact::display_contact_info(void)
{
	if (this->is_empty())
		return (0);
	std::cout << YELLOW "Contact :" RESET <<std::endl;
	std::cout << "+----------------------------+" << std::endl;
	std::cout << "+ " YELLOW "First name\t\t: " RESET << this->get_first_name() <<std::endl;
	std::cout << "+ " YELLOW "Last name\t\t: " RESET << this->get_last_name() <<std::endl;
	std::cout << "+ " YELLOW "Nickname\t\t: " RESET << this->get_nickname() <<std::endl;
	std::cout << "+ " YELLOW "Phone number\t\t: " RESET << this->get_number() <<std::endl;
	std::cout << "+ " YELLOW "Darkest secret\t: " RESET << this->get_darkest_secret() <<std::endl;
	std::cout << "+----------------------------+" << std::endl;
	return (1);
}