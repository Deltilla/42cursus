/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:16 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/27 19:45:45 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

bool PriceDataStore::loadFromFile( const std::string &filepath )
{
	std::ifstream in(filepath.c_str(), std::ios_base::in);
	if (!in.is_open()) {
        std::cerr << "Price: error: Could not open the file" << std::endl;
		return ( false );
	}
	this->map.clear();
	std::string line;
	for ( ; getline(in, line); ) {
		if (line.find("date") != std::string::npos || line.find("value") != std::string::npos)
            continue;
		std::size_t comma = line.find(',');
        if (comma == std::string::npos) {
            this->badImput = true;
            continue;
        }
		std::string key = line.substr(0, comma);
		std::stringstream ssVal(line.substr(comma + 1));
        double value;
        if (!(ssVal >> value))
            this->badImput = true;
		if (value < 0)
			this->negativeNumber = true;
		if (value > __INT_MAX__)
			this->tooLargeNumber = true;
		this->map[key] = value;
	}
	return ( true );
}

typedef std::map<std::string, double> PriceMap;
const PriceMap& PriceDataStore::getMap( void ) const
{
	return ( this->map );
}

bool QuantityDataStore::loadFromFile( const std::string &filepath )
{
	std::ifstream in(filepath.c_str(), std::ios_base::in);
	if (!in.is_open()) {
        std::cerr << "Quantity: error: Could not open the file" << std::endl;
		return ( false );
	}
	this->map.clear();
	std::string line;
	for ( ; getline(in, line); ) {
		if (line.find("date") != std::string::npos || line.find("value") != std::string::npos)
            continue;
		std::size_t comma = line.find('|');
        if (comma == std::string::npos) {
            this->badImput = true;
            continue;
        }
		std::string key = line.substr(0, comma);
        std::string valStr = line.substr(comma + 1);

        std::size_t a = key.find_first_not_of(" \t\r\n");
        std::size_t b = key.find_last_not_of(" \t\r\n");
        if (a == std::string::npos) key.clear();
        else key = key.substr(a, b - a + 1);

        a = valStr.find_first_not_of(" \t\r\n");
        b = valStr.find_last_not_of(" \t\r\n");
        if (a == std::string::npos) valStr.clear();
        else valStr = valStr.substr(a, b - a + 1);
		
		std::stringstream ssVal(valStr);
        double value;
        if (!(ssVal >> value))
            this->badImput = true;
		if (value < 0)
			this->negativeNumber = true;
		if (value > __INT_MAX__)
			this->tooLargeNumber = true;
		this->map[key] = value;
	}
	return ( true );
}

typedef std::map<std::string, double> QuantityMap;
const QuantityMap& QuantityDataStore::getMap( void ) const
{
	return ( this->map );
}

BitcoinExchange::BitcoinExchange( void ) : _priceStore(NULL), _quantityStore(NULL)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange( const PriceDataStore &prices, const QuantityDataStore &quantities ) : _priceStore(NULL), _quantityStore(NULL)
{
	std::cout << "BitcoinExchange assigment constructor called" << std::endl;
	this->_priceStore = new PriceDataStore(prices);
	this->_quantityStore = new QuantityDataStore(quantities);
}


BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) : _priceStore(NULL), _quantityStore(NULL)
{
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    if (copy._priceStore)
        this->_priceStore = new PriceDataStore(*copy._priceStore);
    else
        this->_priceStore = NULL;

    if (copy._quantityStore)
        this->_quantityStore = new QuantityDataStore(*copy._quantityStore);
    else
        this->_quantityStore = NULL;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& copy )
{
    std::cout << "BitcoinExchange copy assigment opperator called" << std::endl;
    if (this != &copy) {
        PriceDataStore *newPriceStore = NULL;
        QuantityDataStore *newQuantityStore = NULL;

        if (copy._priceStore)
            newPriceStore = new PriceDataStore(*copy._priceStore);
        if (copy._quantityStore)
            newQuantityStore = new QuantityDataStore(*copy._quantityStore);

        if (this->_priceStore) {
            delete this->_priceStore;
            this->_priceStore = NULL;
        }
        if (this->_quantityStore) {
            delete this->_quantityStore;
            this->_quantityStore = NULL;
        }

        this->_priceStore = newPriceStore;
        this->_quantityStore = newQuantityStore;
    }
    return ( *this );
}

void BitcoinExchange::setPriceStore( const PriceDataStore &prices )
{
	if (this->_priceStore) {
        delete this->_priceStore;
        this->_priceStore = NULL;
    }
    this->_priceStore = new PriceDataStore(prices);
}

void BitcoinExchange::setQuantityStore( const QuantityDataStore &quantities )
{
	if (this->_quantityStore) {
        delete this->_quantityStore;
        this->_quantityStore = NULL;
    }
    this->_quantityStore = new QuantityDataStore(quantities);
}

void BitcoinExchange::storeValuePerDate( void )
{
	if (!this->_quantityStore) {
        std::cerr << "error: no quantity store available" << std::endl;
        return;
    }

    const std::map<std::string, double> &qmap = this->_quantityStore->getMap();
	const std::map<std::string, double> &pmap = this->_priceStore->getMap();

    for (std::map<std::string, double>::const_iterator it = qmap.begin(); it != qmap.end(); ++it) {
		std::map<std::string, double>::const_iterator pit = pmap.find(it->first);
		if (pit == pmap.end()) {
            std::cerr << "warning: no price for date: " << it->first << std::endl;
            continue;
        }
		double value = pit->second * it->second;
        std::ostringstream ss;
        ss << it->first << " => " << it->second << " = " << value;
        std::string date = ss.str();
		
		this->_map[date] = value;
    }
}

void BitcoinExchange::displayValuesByDate( void ) const
{
	for (std::map<std::string, double>::const_iterator it = this->_map.begin(); it != this->_map.end(); ++it) {
		std::cout << it->first << it->second << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange( void )
{
	std::cout << "BitcoinExchange Destructor called" << std::endl;
	if (this->_priceStore) {
        delete this->_priceStore;
        this->_priceStore = NULL;
    }
    if (this->_quantityStore) {
        delete this->_quantityStore;
        this->_quantityStore = NULL;
    }
}
