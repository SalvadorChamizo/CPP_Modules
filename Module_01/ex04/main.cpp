/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:10:41 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/25 12:03:11 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

void replaceAll(std::string &buffer, const std::string &target, const std::string &replacement) 
{
	size_t pos = 0;
    
	while ((pos = buffer.find(target, pos)) != std::string::npos)
	{
        buffer.erase(pos, target.length());
        buffer.insert(pos, replacement);
        pos += replacement.length();
    }
}

int	openInfile(std::ifstream &inputFile, char *filename)
{
	inputFile.open(filename); // Try to open the infile.
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open the infile." << std::endl;
		return (1);
	}
	return (0);
}

int openOutfile(std::ofstream &outputFile, std::string outfile, char *filename)
{
	outfile.append(filename); // Sets the name for the outfile.
	outfile.append(".replace");
	outputFile.open(outfile.c_str()); // Creates the output file. c_str returns a pointer to a null-terminated character array (C-style string)
	if (!outputFile.is_open())
	{
		std::cout << "Failed to open the outfile." << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		outfile;
	std::string		buffer;
	std::string		line;

	if (argc != 4)	// Checks the number of arguments.
	{
		std::cout << "Incorrect number of arguments." << std::endl;
		return (1);
	}

	if (openInfile(inputFile, argv[1]))
		return (1);

	if (openOutfile(outputFile, outfile, argv[1]))
	{
		inputFile.close();
		return (1);
	}

	while (getline(inputFile, line)) // Read from the infile.
	{
		buffer.append(line);
		buffer.append("\n");
	}

	std::string		target = argv[2];
	std::string		replace = argv[3];

	if (!target.empty()) // Checks if the target is empty or it's equal to the other string.
		replaceAll(buffer, target, replace);

	outputFile << buffer;

	inputFile.close();
	outputFile.close();
	return (0);
}