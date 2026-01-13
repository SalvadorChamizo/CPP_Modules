/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:37:06 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 15:37:08 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", this->gradeSign, this->gradeExecute),
	_target("Standard")
{
	std::cout << "PresidentialPardonForm: Default constructor called\n";
} 

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", this->gradeSign, this->gradeExecute),
	_target(target)
{
	std::cout << "PresidentialPardonForm: Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm: Copy constructor called\n";
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void		PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}
