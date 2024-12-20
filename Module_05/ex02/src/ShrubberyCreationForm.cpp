/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:31:37 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 14:54:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", this->gradeSign, this->gradeExecute),
	_target("Standard")
{
	std::cout << "ShrubberyCreationForm: Default constructor called\n";
} 

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", this->gradeSign, this->gradeExecute),
	_target(target)
{
	std::cout << "ShrubberyCreationForm: Constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called\n";
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void		ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	out;
	std::string		outfile;

	outfile.append(this->_target);
	outfile.append("_shrubbery");
	out.open(outfile.c_str());
	if (out.is_open())
	{
		out << "       _-_\n";
		out << "    (~~   ~~)\n";
		out << " ((~~       ~~))\n";
		out << "{               }\n";
		out << " (   -     -   )\n";
		out << "   (  (   )  )\n";
		out << " - -   | | _- _\n";
		out << "  _ -  | |   -_\n";
		out << "      (( ))\n";
		out.close();
		std::cout << "Shrubbery planted in " << outfile << ".\n";
	}
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}
