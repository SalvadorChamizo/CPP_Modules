/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:31:03 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 14:43:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {

	private:
		const std::string	_target;
		const int	_gradeSign = 145;
		const int	_gradeExecute = 137;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

		std::string		getTarget(void) const;

		void			beExecuted(void) const;

		static int const	gradeSign = 145;
		static int const	gradeExecute = 137;
};

#endif