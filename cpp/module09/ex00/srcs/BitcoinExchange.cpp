/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:16 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/25 18:14:47 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange( void )
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	this->_max = 0;
	this->_full = true;
}

BitcoinExchange::BitcoinExchange( unsigned int N )
{
	std::cout << "BitcoinExchange assigment constructor called" << std::endl;
	this->_max = N;
	this->_full = false;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy )
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	this->_max = copy._max;
	this->_full = copy._full;
	this->_nums = copy._nums;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& copy )
{
    std::cout << "BitcoinExchange copy assigment opperator called" << std::endl;
	if (this != &copy) {
		this->_max = copy._max;
		this->_full = copy._full;
		this->_nums = copy._nums;
	}
    return ( *this );
}

bool BitcoinExchange::getFull( void ) const
{
	return ( this->_full );
}

std::vector<int> BitcoinExchange::getNums( void ) const
{
	return ( this->_nums );
}

void BitcoinExchange::addNumber( int n )
{
	if (this->_full)
		throw BitcoinExchange::MaxStoredException();
	this->_nums.push_back(n);
	if (this->_nums.size() == this->_max)
		this->_full = true;
}

int BitcoinExchange::shortestBitcoinExchange( void )
{
    if (this->_nums.size() < 2)
        throw std::runtime_error("Not enough numbers to find a BitcoinExchange");

    std::vector<int> tmp(this->_nums);
    std::sort(tmp.begin(), tmp.end());

    int best = std::numeric_limits<int>::max();
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = static_cast<int>(tmp[i]) - static_cast<int>(tmp[i - 1]);
        if (diff < best) best = diff;
        if (best == 0) return 0;
    }
    return best;
}

int	BitcoinExchange::longestBitcoinExchange( void )
{
	if (this->_nums.size() < 2)
        throw std::runtime_error("Not enough numbers to find a BitcoinExchange");

    std::vector<int>::const_iterator itMin = std::min_element(this->_nums.begin(), this->_nums.end());
    std::vector<int>::const_iterator itMax = std::max_element(this->_nums.begin(), this->_nums.end());

    return ( static_cast<long long>(*itMax) - static_cast<long long>(*itMin) );
}

BitcoinExchange::~BitcoinExchange( void )
{
	std::cout << "BitcoinExchange Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& bitcoinExchange)
{
	for (size_t i = 0; i < bitcoinExchange.getNums().size(); i++)
   		os << "Position "<< i << ": " << bitcoinExchange.getNums().at(i) << std::endl;
    return os;
}