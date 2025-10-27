/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/27 19:40:32 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <algorithm>
# include <map>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <sstream>

struct PriceDataStore
{
	public:
	
		typedef std::map<std::string, double> PriceMap;

		bool loadFromFile( const std::string &filepath );

		const PriceMap&	getMap() const;
    	bool			hasMap( const std::string &date ) const;

		double priceForDate( const std::string &date, bool &found ) const;

	private:
		
		PriceMap map;

		bool badImput = false;
    	bool negativeNumber = false;
		bool tooLargeNumber = false;
};

struct QuantityDataStore
{
	public:
		
		typedef std::map<std::string, double> QuantityMap;

		bool loadFromFile(const std::string &filepath);

		const QuantityMap&	getMap() const;
    	bool				hasMap(const std::string &date) const;

		double priceForDate(const std::string &date, bool &found) const;

	private:
		
		QuantityMap map;

		bool badImput = false;
    	bool negativeNumber = false;
		bool tooLargeNumber = false;
};

class BitcoinExchange
{

	typedef std::map<std::string, double> ExchangeMap;
	
	public:

    	BitcoinExchange();
		BitcoinExchange( const PriceDataStore &prices, const QuantityDataStore &quantities );
    	BitcoinExchange( const BitcoinExchange& copy );
		BitcoinExchange& operator=( const BitcoinExchange& copy );
    	~BitcoinExchange();

		void setPriceStore( const PriceDataStore &prices );
    	void setQuantityStore( const QuantityDataStore &quantities );

		void	storeValuePerDate( void );
		
		void	displayValuesByDate() const;

	private:
	
		ExchangeMap _map;
		const PriceDataStore *_priceStore;
    	const QuantityDataStore *_quantityStore;

};

#endif