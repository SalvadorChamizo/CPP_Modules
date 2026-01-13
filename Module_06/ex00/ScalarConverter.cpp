/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:52 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/06 15:44:07 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	convertCharacter(const std::string &str);
static void	convertInteger(const std::string &str);
static void	convertFloat(const std::string &str);
static void	convertDouble(const std::string &str);
static void	convertInfiniteDouble(const std::string &str);
static void	convertInfiniteFloat(const std::string &str);

static std::string	ft_strtrim(const std::string &str);
static bool	hasFractionalPart(float number);
static int	checkOutOfRange(const std::string &str);

/* ************************************************************************** */
/*                         Constructor & Destructor                           */
/* ************************************************************************** */

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter: Default constructor called\n";
} 

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter: Copy constructor called\n";
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter: Destructor called\n";
}

/* ************************************************************************** */
/*                            Operators overload                              */
/* ************************************************************************** */

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter: Copy operator overload called\n";
	if (this == &other)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
/* ************************************************************************** */

void		ScalarConverter::convert(const std::string &input)
{
	std::string	str;
	char		*str_end;

	str = ft_strtrim(input);
	if (str.empty())
	{
		std::cout << "Invalid input. The string is empty.\n";
		return ;
	}
	if (str == "-inff" || str == "+inff" || str == "nanf") // handle infinite float
	{
		convertInfiniteFloat(str);
		return ;
	}
	if (str == "-inf" || str == "+inf" || str == "nan") // handle infinite double
	{
		convertInfiniteDouble(str);
		return ;
	}
	if (input.length() == 1 && ((input[0] >= ' ' && input[0] <= '/')
		|| (input[0] >= ':' && input[0] <= 'z')))
	{
		convertCharacter(str);
		return ;
	}
	strtol(str.c_str(), &str_end, 10);
	if (str_end[0] == '\0')
	{
		convertInteger(str);
		return ;
	}
	strtod(str.c_str(), &str_end);
	if (str_end[0] == 'F' || str_end[0] == 'f')
	{
		convertFloat(str);
		return ;
	}
	if (str_end[0] == '\0')
	{
		convertDouble(str);
		return ;
	}

}

/* ************************************************************************** */
/*                          Convertion functions                              */
/* ************************************************************************** */

static void	convertCharacter(const std::string &str)
{
	char	c;

	c = str[0];
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
	return ;
}

static void	convertInteger(const std::string &str)
{
	int	i;
	
	if (checkOutOfRange(str))
		return ;
	i = atoi(str.c_str());
	if (isprint(static_cast<char>(i)) != 0)
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << ".0f\n";
	std::cout << "double: " << static_cast<double>(i) << ".0\n";
	return ;
}

static void	convertFloat(const std::string &str)
{
	float	f;

	if (checkOutOfRange(str))
		return ;
	f = atof(str.c_str());
	if (!hasFractionalPart(f) && isprint(static_cast<char>(f)) != 0)
		std::cout << "char: '" << static_cast<char>(f) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(f) << "\n";
	std::cout << "float: " << f << (hasFractionalPart(f) ? "f" : ".0f") << "\n";
	std::cout << "double: " << static_cast<double>(f) << (hasFractionalPart(f) ? "" : ".0") << "\n";
	return ;
}

static void	convertDouble(const std::string &str)
{
	double	d;

	if (checkOutOfRange(str))
		return ;
	d = atof(str.c_str());
	if (!hasFractionalPart(d) && isprint(static_cast<char>(d)) != 0)
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(d) << "\n";
	std::cout << "float: " << static_cast<float>(d) << (hasFractionalPart(d) ? "f" : ".0f") << "\n";
	std::cout << "double: " << d << (hasFractionalPart(d) ? "" : ".0") << "\n";
	return ;
}

static void	convertInfiniteFloat(const std::string &str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << str << "\n";
	std::cout << "double: " << str.substr(0, str.length() - 1) << "\n";
}

static void	convertInfiniteDouble(const std::string &str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << str << "f\n";
	std::cout << "double: " << str << "\n";
}

/* ************************************************************************** */
/*                               Help functions                               */
/* ************************************************************************** */

static std::string	ft_strtrim(const std::string &str)
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

static bool	hasFractionalPart(float number)
{
	return (number != static_cast<int>(number));
}

static int	checkOutOfRange(const std::string &str)
{
	if (atol(str.c_str()) > INT_MAX || atol(str.c_str()) < INT_MIN)
	{
		std::cout << "char: Out of range\n";
		std::cout << "int: Out of range\n";
		std::cout << "float: Out of range\n";
		std::cout << "double: Out of range\n";
		return (1);
	}
	return (0);
}
