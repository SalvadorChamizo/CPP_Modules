/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:34 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/11 18:15:37 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"

int	main(void)
{
	Bureaucrat	Anselmo("Anselmo", 2);
	Bureaucrat	Manolo("Manolo", 46);
	Intern	someIntern;
	AForm	*rrf = NULL;
	AForm	*scf = NULL;
	AForm	*ppf = NULL;

	try
	{
		std::cout << "\n****    RobotomyRequestForm Test    ****\n\n";

		rrf = someIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << "\n";
		Anselmo.signForm(*rrf);
		Anselmo.executeForm(*rrf);

		std::cout << "\n****    ShrubberyCreatoonForm Test    ****\n\n";

		scf = someIntern.makeForm("shrubbery creation", "Tree");
		std::cout << *scf << "\n";
		Manolo.executeForm(*scf);
		Manolo.signForm(*scf);
		Manolo.executeForm(*scf);

		std::cout << "\n****    PresidentialPardonForm Test    ****\n\n";

		ppf = someIntern.makeForm("presidential pardon", "Nicolas Cage");
		std::cout << *ppf << "\n";
		Manolo.signForm(*ppf);
		Manolo.executeForm(*ppf);
		Anselmo.executeForm(*ppf);
		Anselmo.signForm(*ppf);
		Anselmo.executeForm(*ppf);

		std::cout << "\n";
	}
	catch (Intern::MakeFormFailedException &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	if (rrf)
		delete rrf;
	if (scf)
		delete scf;
	if (ppf)
		delete ppf;
	return (0);
}