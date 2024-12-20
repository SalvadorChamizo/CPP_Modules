/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:11:56 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/03 19:40:39 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
# define AFORM_HPP

# include <string.h>
# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {

	private:
		const	std::string _name;
		bool				_signed;
		const	int			_gradeSign;
		const	int			_gradeExecute;

		AForm();

	public:
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);
		friend std::ostream &operator<<(std::ostream &out, const AForm &f);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeSign(void) const;
		int				getGradeExecute(void) const;

		void			beSigned(const Bureaucrat &b);
		void			execute(Bureaucrat const & executor) const;

		virtual void	beExecuted(void) const = 0;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif