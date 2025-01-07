/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:11:44 by schamizo          #+#    #+#             */
/*   Updated: 2025/01/07 14:50:44 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	data = {30, 40.0f, 24.5, 'p', "hello world"};
	unsigned long	raw = Serializer::serialize(&data);
	Data	*data2 = Serializer::deserialize(raw);

	std::cout << "int data: " << data.intValue << "\n";
	std::cout << "int data2: " << data2->intValue << "\n";
	std::cout << "float data: " << data.floatValue << "\n";
	std::cout << "float data2: " << data2->floatValue << "\n";
	std::cout << "double data: " << data.doubleValue << "\n";
	std::cout << "double data2: " << data2->doubleValue << "\n";
	std::cout << "char data: " << data.charValue << "\n";
	std::cout << "char data2: " << data2->charValue << "\n";
	std::cout << "string data: " << data.stringValue << "\n";
	std::cout << "string data2: " << data2->stringValue << "\n";
}