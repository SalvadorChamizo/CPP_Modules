/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:47:28 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/10 12:45:10 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {

	private:
		const	std::string _name;
		bool				_signed;
		const	int			_gradeSign;
		const	int			_gradeExecute;

		Form();

	public:
		Form(std::string name, int gradeSign, int gradeExecute);
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &other);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExecute(void) const;

		void		beSigned(const Bureaucrat &b);

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif