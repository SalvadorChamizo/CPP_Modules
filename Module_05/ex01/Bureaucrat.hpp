/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:33:06 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/03 15:58:50 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class	Form;

class	Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &other);
		friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &bu);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(Form &f) const;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
