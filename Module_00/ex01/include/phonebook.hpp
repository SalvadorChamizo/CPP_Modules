/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:25:46 by schamizo          #+#    #+#             */
/*   Updated: 2024/10/11 17:04:26 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "iostream"
# include <chrono>
# include <thread>

void	terminal_clear(void);
void	display_selection_menu(void);
void	sleep_one_second(void);
void	eof_handle(void);
int		error_handle(void);

#endif