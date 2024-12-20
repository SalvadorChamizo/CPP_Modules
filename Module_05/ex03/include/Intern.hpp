/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:34:53 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 16:53:44 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern {

	private:
		AForm	*createPresiPardonForm(std::string target);
		AForm	*createRobotoRequestForm(std::string target);
		AForm	*createShrubberyCreationForm(std::string target);

	public:
		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern	&operator=(const Intern &other);

		AForm	*makeForm(std::string formName, std::string formTarget);
};

typedef	AForm* (Intern::*forms)(std::string target);

#endif