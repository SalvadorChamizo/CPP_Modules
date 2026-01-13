/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:26:29 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 15:19:28 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"

int	main(void)
{
	Bureaucrat	Anselmo("Anselmo", 2);
	Bureaucrat	Manolo("Manolo", 46);
	Bureaucrat	Antonia("Antonia", 138);
	Bureaucrat	Paco(Antonia);

	std::cout << "\n****    RobotomyRequestForm Test    ****\n\n";

	AForm	*form1 = new RobotomyRequestForm("Robot");
	std::cout << "\n" << *form1 << "\n";
	Anselmo.executeForm(*form1);
	Anselmo.signForm(*form1);
	std::cout << "\n" << *form1 << "\n";
	Manolo.executeForm(*form1);
	Anselmo.executeForm(*form1);

	std::cout << "\n****    ShrubberyCreationForm Test    ****\n\n";

	AForm	*form2 = new ShrubberyCreationForm("Tree");
	std::cout << "\n" << *form2 << "\n";
	Antonia.executeForm(*form2);
	Anselmo.signForm(*form2);
	std::cout << "\n" << *form2 << "\n";
	Antonia.executeForm(*form2);
	Anselmo.executeForm(*form2);

	std::cout << "\n****    PresidentialPardonForm Test    ****\n\n";

	AForm	*form3 = new PresidentialPardonForm("Nicolas Cage");
	std::cout << "\n" << *form3 << "\n";
	Anselmo.signForm(*form3);
	std::cout << "\n" << *form3 << "\n";
	Anselmo.executeForm(*form3);
	std::cout << "\n\n";

	delete form1;
	delete form2;
	delete form3;

	return (0);
}