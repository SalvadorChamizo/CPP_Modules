/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:39:26 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 16:55:15 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Intern::Intern()
{
	std::cout << "Intern: Default constructor called\n";
} 

Intern::Intern(const Intern &other)
{
	std::cout << "Intern: Copy constructor called\n";
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

AForm	*Intern::createRobotoRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresiPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	names[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	forms		forms[] = {&Intern::createRobotoRequestForm, &Intern::createPresiPardonForm, &Intern::createShrubberyCreationForm};
	AForm		*formToCreate = NULL;
	int			i;
	
	for (i = 0; i < 3; i++)
	{
		if (!names[i].compare(formName))
		{
			formToCreate = (this->*forms[i])(formTarget);
			std::cout << "Intern creates " << formToCreate->getName() << " form.\n";
			break ;
		}
	}
	if (i == 3)
	{
		std::cerr << "Error: There is not form for name " << formName << ".\n";
	}
	return (formToCreate);
}
