/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:55:24 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 19:44:38 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "phonebook.hpp"
# include <iostream>
# include <string>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\033[37m"
# define GREYM		"\x1B[38;5;245m"
# define GREYM2		"\x1B[38;5;250m"
# define BOLD		"\033[1m"
# define UNDERLINE "\033[4m"
# define RESET		"\x1b[0m"
# define CLEAR		"\033[2J"
# define ITALIC "\033[3m"

class	Contact {

	/* Class variables*/
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		int			_phone_number;
		std::string	_darkest_secret;

	/* Class methods */
	public:
		Contact(void);
		~Contact(void);
		std::string	get_first_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		int			get_number(void);
		std::string get_darkest_secret(void);
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nickname(std::string str);
		void		set_number(int nbr);
		void		set_darkest_secret(std::string str);
		int			is_empty(void);
		int			display_contact_info(void);
};

#endif