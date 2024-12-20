/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:30:30 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/03 13:03:18 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	return (0);
}