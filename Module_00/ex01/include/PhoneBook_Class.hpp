/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:20:48 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 19:44:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "phonebook.hpp"
# include <iostream>
# include "Contact_Class.hpp"

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

class	PhoneBook {

	private:
		Contact	_contact_list[8];
		int		_index;
		int		_abort;

	/* Methods */
	private:
		int			_increment_index(void);
		int			_add_contact_field_nbr(std::string str);
		std::string	_add_contact_field(std::string str);
		void		_print_contact_string(std::string str);
		void		_print_contact_table(int index);
		void		_print_search_table(void);
		int			_display_index(int index);
		void		_search_loop(void);

	public:
				PhoneBook(void);
				~PhoneBook(void);
		void	add(void);
		void	search(void);
		void	exit_message(void);
};

# endif