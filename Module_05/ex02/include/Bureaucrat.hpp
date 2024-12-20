/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:28:12 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/03 19:21:29 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class	AForm;

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

		void		signForm(AForm &f) const;
		void		executeForm(AForm const & form);

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
