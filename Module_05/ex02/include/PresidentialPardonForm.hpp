/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:56:34 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/07 14:39:35 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonFORM_HPP
# define PresidentialPardonFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

	private:
		const std::string	_target;
		static const int	_gradeSign = 25;
		static const int	_gradeExecute = 5;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);

		std::string		getTarget(void) const;

		void			beExecuted(void) const;

		static int const	gradeSign = 25;
		static int const	gradeExecute = 5;
};

#endif