/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:05:04 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/03 16:06:04 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void    createForm(std::string name, int gradeSign, int gradeExecute)
{
    try
    {
        Form    Test(name, gradeSign, gradeExecute);
        std::cout << "\n";
        std::cout << Test << "\n";
        std::cout << "\n";
    }
    catch (Form::GradeTooHighException &f)
    {
        std::cerr << "Exception: " << f.what() << "\n";
    }
    catch (Form::GradeTooLowException &f)
    {
        std::cerr << "Exception: " << f.what() << "\n";
    }
}

void    signFormTest(Form &form, Bureaucrat &bureaucrat)
{
    std::cout << form << "\n";
    bureaucrat.signForm(form);
    std::cout << form << "\n";
}

void	createBureaucrat(std::string name, int grade)
{
	try
	{
		Bureaucrat	Test(name, grade);
		std::cout << "\n";
		std::cout << Test;
		std::cout << "\n";
	}
	catch (Bureaucrat::GradeTooHighException &b)
	{
		std::cerr << "Exception: " << b.what() << "\n";
	}
	catch (Bureaucrat::GradeTooLowException &b)
	{
		std::cerr << "Exception: " << b.what() << "\n";
	}
}

void	incrementGradeTest(Bureaucrat Test)
{
	try
	{
		std::cout << "\n";
		Test.incrementGrade();
		Test.incrementGrade();
		std::cout << Test;
		std::cout << "\n";
	}
	catch (Bureaucrat::GradeTooHighException &b)
	{
		std::cerr << "Exception: " << b.what() << "\n";
	}
	catch (Bureaucrat::GradeTooLowException &b)
	{
		std::cerr << "Exception: " << b.what() << "\n";
	}
}

void	decrementGradeTest(Bureaucrat Test)
{
	try
	{
		std::cout << "\n";
		Test.decrementGrade();
		Test.decrementGrade();
		std::cout << Test;
		std::cout << "\n";
	}
	catch (Bureaucrat::GradeTooHighException &b)
	{
		std::cerr << "Exception: " << b.what() << "\n";
	}
	catch (Bureaucrat::GradeTooLowException &b)
	{
		std::cerr << "Exception: " << b.what() << "\n";
	}
}

int	main(void)
{
	Bureaucrat	Anselmo("Anselmo", 2);
	Bureaucrat	Manolo("Manolo", 150);
	Bureaucrat	Antonia("Antonia", 149);
	Bureaucrat	Paco(Antonia);

	std::cout << "\nBureaucrat Test\n\n";

	std::cout << "Create bureaucrat test\n\n";

	createBureaucrat("Pepe", -1);
	createBureaucrat("Luis", 50);
	createBureaucrat("Frígida", 150);
	createBureaucrat("Tomasina", 200);

	std::cout << "\nIncrement grade test\n\n";

	incrementGradeTest(Anselmo);
	incrementGradeTest(Antonia);

	std::cout << "\nDecrement grade test\n\n";

	decrementGradeTest(Paco);
	decrementGradeTest(Manolo);

	std::cout << "\nForm Test\n\n";

	std::cout << "Create Form test\n\n";

	createForm("Form1", 1, 2);
	createForm("Form2", 50, 20);
	createForm("Form3", 150, 151);
	createForm("Form4", -1, 10);

    Form form1("form1", 10, 10);
    std::cout << form1 << "\n";
    Anselmo.signForm(form1);
    std::cout << form1 << "\n";

	return (0);
}