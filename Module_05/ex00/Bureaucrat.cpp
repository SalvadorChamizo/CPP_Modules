/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:30:42 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/10 12:41:32 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Bureaucrat::Bureaucrat() : _name("Guy"), _grade(150)
{
	std::cout << "Bureaucrat: Default constructor called\n";
} 

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: Constructor called\n";
	if (_grade <= 0)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	std::cout << "Bureaucrat: Copy constructor called\n";
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bu)
{
	out << bu.getName() << ", bureaucrat grade " << bu.getGrade() << ".\n";
	return (out);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */


void		Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "The grade of " << this->getName() << " has been incremented.\n";
}

void		Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "The grade of " << this->getName() << " has been decremented.\n";
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high. Maximum grade is 1.");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low. Minimum grade is 150.");
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}