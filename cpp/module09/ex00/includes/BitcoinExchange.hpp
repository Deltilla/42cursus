/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/25 19:38:13 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <algorithm>
# include <map>
# include <iostream>
# include <stdexcept>

struct PriceDataStore
{
	public:
	
		typedef std::map<std::string, double> PriceMap;

		bool loadFromFile(const std::string &filepath);

		const PriceMap&	getData() const;
    	bool			hasMap(const std::string &date) const;

		double priceForDate(const std::string &date, bool &found) const;

	private:
		
		PriceMap map;

		static bool isValidPriceToken(const std::string &token);
    	static bool isValidPriceValue(double value);
};

struct QuantityDataStore
{
	public:
		
		typedef std::map<std::string, double> QuantityMap;

		bool loadFromFile(const std::string &filepath);

		const QuantityMap&	getData() const;
    	bool				hasMap(const std::string &date) const;

		double priceForDate(const std::string &date, bool &found) const;

	private:
		
		QuantityMap map;

		static bool isValidPriceToken(const std::string &token);
    	static bool isValidPriceValue(double value);
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

		double computeExchange( bool &ok ) const;

		ExchangeMap computeUSDPerDate( bool &ok ) const;

	private:
	
		const PriceDataStore *_priceStore;
    	const QuantityDataStore *_quantityStore;

};

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& bitcoinexchange);

#endif