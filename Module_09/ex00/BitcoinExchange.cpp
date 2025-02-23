/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:18:51 by schamizo          #+#    #+#             */
/*   Updated: 2025/02/23 19:11:19 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                             Program functions                              */
/* ************************************************************************** */

void	fillMapWithDatabase(std::ifstream &infile, std::map<std::string, double> &bitcoinMap)
{
	std::string	line;

	getline(infile, line);
	while (std::getline(infile, line))
	{
		std::istringstream 	lineStream(line);
		std::string			date;
		std::string			value;

		if (std::getline(lineStream, date, ',') && std::getline(lineStream, value))
		{
			bitcoinMap[date] = atof(value.c_str());
		}	
	}
}

void	compareMapWithInputFile(std::ifstream &infile, std::map<std::string, double>	&btc)
{
	std::string	line;

	while (std::getline(infile, line))
	{
		std::istringstream	lineStream(line);
		std::string			date;
		std::string			value;

		std::getline(lineStream, date, '|');
		std::getline(lineStream, value);

		date = ft_strtrim(date);
		value = ft_strtrim(value);

		if (!checkCorrectDate(date))
			continue ;
		if (!checkCorrectValue(value))
			continue ;

		std::map<std::string, double>::iterator it = btc.lower_bound(date);
		if (it == btc.end())
			--it;
		if (it != btc.begin() && it->first > date)
			--it;
		
        std::stringstream ss;
        ss << std::setprecision(10) << it->second * atof(value.c_str());
        std::string formattedResult = ss.str();
		std::cout << ft_strtrim(date) << " => " << value << " = " << formattedResult << "\n";
	}

}

/* ************************************************************************** */
/*                            Parsing functions                               */
/* ************************************************************************** */

bool	checkArgumentCounter(int argc)
{
	if (argc == 1)
	{
		std::cerr << "Error: could not open file.\n";
		return (false);
	}
	if (argc > 2)
	{
		std::cerr << "Error: invalid argument number.\n";
		return (false);
	}
	return (true);
}

bool	checkDateFormat(std::string date)
{
	int	i = 0;
	const char	*dateInChar = date.c_str();

	while (dateInChar[i] != '\0')
	{
		if (i <= 3 && !isdigit(dateInChar[i]))
			return (false);
		if (i == 4 && dateInChar[i] != '-')
			return (false);
		if (i > 4 && i <= 6 && !isdigit(dateInChar[i]))
			return (false);
		if (i == 7 && dateInChar[i] != '-')
			return (false);
		if (i > 7 && i <= 9 && !isdigit(dateInChar[i]))
			return (false);
		if (i > 9)
			return (false);
		i++;
	}
	return (true);
}

bool	checkYearMonthAndDay(int year, int month, int day)
{	
	if (year < 2009 || year > 2024 || month <= 0 || month > 12 || day <= 0 || day > 31)
		return (false);
	if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER)
	{
		if (day > 30)
			return (false);
	}
	if (month == FEBRUARY)
	{
		if (year == 2012 || year == 2016 || year == 2020)
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	return (true);
}

bool	checkCorrectDate(std::string date)
{
	if (!checkDateFormat(date))
	{
		if (date != "date")
			std::cout << "Error: invalid format => " << date << "\n";
		return (false);
	}

	std::string	year = date.substr(0, 4);
	std::string	month = date.substr(5, 2);
	std::string	day = date.substr(8, 2);

	if (!checkYearMonthAndDay(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str())))
	{
		std::cout << "Error: bad input => " << date << "\n";
		return (false);
	}
	return (true);
}

bool	checkCorrectValue(std::string valueString)
{
	int dot_count = 0;
	int minus_count = 0;

	if (valueString.empty())
	{
		std::cout << "Error: bad input.\n";
		return (false);
	}
	
	for (size_t i = 0; i < valueString.size(); i++)
	{
		if (!isdigit(valueString[i]) && valueString[i] != '.' && valueString[i] != '-')
		{
			std::cout << "Error: invalid format => " << valueString << "\n";
			return (false);
		}
		if (valueString[i] == '.')
			dot_count++;
		if (valueString[i] == '-')
			minus_count++;
		if (dot_count > 1 || minus_count > 1)
		{
			std::cout << "Error: invalid format => " << valueString << "\n";
			return (false);
		}
	}

	long double	value = atof(valueString.c_str());
	if (value < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return (false);
	}
	if (value > std::numeric_limits<float>::max() || value > std::numeric_limits<int>::max())
	{
		std::cout << "Error: too large a number.\n";
		return (false);
	}
	return (true);
}

/* ************************************************************************** */
/*                               Help functions                               */
/* ************************************************************************** */

std::string	ft_strtrim(const std::string &str)
{
	std::string::size_type	i = 0;
	std::string::size_type	j = str.size() - 1;

	if (str.empty() || (str.size() == 1 && str[0] == ' '))
		return (str);
	while (i < str.size() && isspace(str[i]))
		i++;
	while (isspace(str[j]))
		j--;
	return (str.substr(i, j - i + 1));
}
