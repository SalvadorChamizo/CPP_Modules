/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:06:45 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/16 12:57:51 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define FLT_MAX 3.40282347e+38F
# define FLT_MIN 1.17549435e-38F

# include <fstream>
# include <iostream>
# include <map>
# include <unordered_map>
# include <sstream>
# include <limits>
# include <cmath>

typedef enum e_months
{
	NON_VALID,
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
} 	t_months;

/* Program functions */

void		fillMapWithDatabase(std::ifstream &infile, std::map<std::string, double> &bitcoinMap);
void		compareMapWithInputFile(std::ifstream &infile, std::map<std::string, double>	&btc);

/* Parsing functions */

bool		checkArgumentCounter(int argc);
bool		checkDateFormat(std::string date);
bool		checkYearMonthAndDay(int year, int month, int day);
bool		checkCorrectDate(std::string date);
bool		checkCorrectValue(std::string valueString);

/* Help functions */

std::string	ft_strtrim(const std::string &str);

#endif