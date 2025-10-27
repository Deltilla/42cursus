/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/27 19:19:42 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main( int arc, char** arv )
{
	if (arc == 2)
	{
		try {
			PriceDataStore		prices;
			QuantityDataStore	quantities;
			if (prices.loadFromFile("data.csv") && quantities.loadFromFile(arv[1])) {
				BitcoinExchange exchange(prices, quantities);
				exchange.storeValuePerDate();
				exchange.displayValuesByDate();
			}
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
			
	}
	else
        std::cerr << "error: wrong paramaters" << std::endl
                << "./btc imput.txt" << std::endl;
}