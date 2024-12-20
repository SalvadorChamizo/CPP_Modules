/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:36:58 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/04 14:44:37 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

	private:
		const std::string	_target;
		const int	_gradeSign = 72;
		const int	_gradeExecute = 45;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

		std::string		getTarget(void) const;

		void			beExecuted(void) const;

		static int const	gradeSign = 72;
		static int const	gradeExecute = 45;
};

#endif