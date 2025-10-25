/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/25 19:39:35 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <fstream>

int main( int arc, char** arv )
{
	if (arc == 2)
	{
		std::ifstream database("../data.csv", std::ios_base::in);
		if (!database.is_open())
            std::cerr << "error: Could not open the database" << std::endl;
		std::ifstream imput(arv[1], std::ios_base::in);
		if (!imput.is_open())
            std::cerr << "error: Could not open the file" << std::endl;

		std::string line;
		while (getline(imput, line))
		{
			QuantityDataStore::loadFromFile
		}
		database.close();
		imput.close();
	}
	else
        std::cerr << "error: wrong paramaters" << std::endl
                << "./btc imput.txt" << std::endl;
}