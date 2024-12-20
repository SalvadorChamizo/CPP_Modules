/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:51 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 15:35:55 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

AForm::AForm()
	: _name("Form"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "AForm: Default constructor called\n";
} 

AForm::AForm(std::string name, int gradeSign, int gradeExecute)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "AForm: Constructor called\n";
	if (_gradeSign <= 0 || _gradeExecute <= 0)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLowException();
	return ;
}

AForm::AForm(const AForm &other) 
: _name(other._name),
_gradeSign(other._gradeSign),
_gradeExecute(other._gradeExecute)
{
	std::cout << "AForm: Copy constructor called\n";
	*this = other;
}

AForm::~AForm()
{
	std::cout << "AForm: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	this->_signed = other.getSigned();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "Form name: " << f.getName() << ", Signed: " << f.getSigned();
	out << ", Grade to sign: " << f.getGradeSign() << ", Grade to execute: " << f.getGradeExecute();
	return (out);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */


void		AForm::beSigned(const Bureaucrat &bu)
{
	if (bu.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
}

void		AForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw	FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw	GradeTooLowException();
	this->beExecuted();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed.");
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSigned(void) const
{
	return (this->_signed);
}

int			AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int			AForm::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}
