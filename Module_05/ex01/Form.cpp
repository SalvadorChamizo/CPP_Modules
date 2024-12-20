/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:20:17 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/03 17:37:45 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

Form::Form()
	: _name("Form"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Form: Default constructor called\n";
} 

Form::Form(std::string name, int gradeSign, int gradeExecute)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "Form: Constructor called\n";
	if (_gradeSign <= 0 || _gradeExecute <= 0)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLowException();
	return ;
}

Form::Form(const Form &other) 
: _name(other._name),
_gradeSign(other._gradeSign),
_gradeExecute(other._gradeExecute)
{
	std::cout << "Form: Copy constructor called\n";
	*this = other;
}

Form::~Form()
{
	std::cout << "Form: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

Form &Form::operator=(const Form &other)
{
	std::cout << "Form: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	this->_signed = other.getSigned();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form name: " << f.getName() << ", Signed: " << f.getSigned();
	out << ", Grade to sign: " << f.getGradeSign() << ", Grade to execute: " << f.getGradeExecute();
	return (out);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */


void		Form::beSigned(const Bureaucrat &bu)
{
	if (bu.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSigned(void) const
{
	return (this->_signed);
}

int			Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int			Form::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}
