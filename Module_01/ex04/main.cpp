/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:10:41 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/15 12:42:24 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		outfile;
	std::string		buffer;
	std::string		line;
	int				pos;

	pos = 0;
	if (argc != 4)	// Checks the number of arguments.
	{
		std::cout << "Incorrect number of arguments." << std::endl;
		return (1);
	}
	inputFile.open(argv[1]); // Try to open the infile.
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open the infile." << std::endl;
		return (1);
	}
	outfile.append(argv[1]); // Sets the name for the outfile.
	outfile.append(".replace");
	outputFile.open(outfile.c_str()); // Creates the output file. c_str returns a pointer to a null-terminated character array (C-style string)
	if (!outputFile.is_open())
	{
		std::cout << "Failed to open the outfile." << std::endl;
		inputFile.close();
		return (1);
	}
	while (getline(inputFile, line)) // Read from the infile.
	{
		buffer.append(line);
		buffer.append("\n");
	}
	line = argv[2]; //Stores the target string into line.
	if (line.empty() && strcmp(argv[3], argv[2])) // Checks if the target is empty or it's equal to the other string.
	{
		while (pos != std::string::npos)
		{
			pos = buffer.find(line.c_str(), 0, line.length());
			outfile = buffer.substr(0, pos);
			
		}
	}
	inputFile.close();
	outputFile.close();
	return (0);
}