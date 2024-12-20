/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:01:29 by schamizo          #+#    #+#             */
/*   Updated: 2024/12/16 12:52:35 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream infileDataBase;
	std::ifstream infile;
	std::string		filename;
	std::map<std::string, double>	mapDatabase;

	if (!checkArgumentCounter(argc))
		return (1);

	infileDataBase.open("./data.csv");
	if (!infileDataBase.is_open())
	{
		std::cerr << "Error: could not open file \"data.csv\".\n";
		return (1);
	}

	filename = argv[1];
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file \"" << filename << "\".\n";
		infileDataBase.close();
		return (1);
	}

	fillMapWithDatabase(infileDataBase, mapDatabase);
	compareMapWithInputFile(infile, mapDatabase);

	infileDataBase.close();
	infile.close();
}
