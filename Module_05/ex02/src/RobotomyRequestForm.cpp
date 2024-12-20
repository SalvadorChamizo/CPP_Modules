/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:40:51 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 15:15:49 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", this->gradeSign, this->gradeExecute),
	_target("Standard")
{
	std::cout << "RobotomyRequestForm: Default constructor called\n";
} 

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", this->gradeSign, this->gradeExecute),
	_target(target)
{
	std::cout << "RobotomyRequestForm: Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm: Copy constructor called\n";
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void		RobotomyRequestForm::beExecuted(void) const
{
    std::srand(time(0));

    int randomNumber = std::rand();
	std::cout << "Beep-beep ... clang .... beep-bepp\n"; 
	if (randomNumber % 2)
	{
		std::cout << this->_target << " has been robotomized successfully.\n";
	}
	else
	{
		std::cout << this->_target << " robotomy failed.\n";
	}
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
