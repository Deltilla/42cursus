/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:16 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/24 12:24:49 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

Span::Span( void )
{
	std::cout << "Span default constructor called" << std::endl;
	this->_max = 0;
	this->_full = true;
}

Span::Span( unsigned int N )
{
	std::cout << "Span assigment constructor called" << std::endl;
	this->_max = N;
	this->_full = false;
}

Span::Span( const Span& copy )
{
	std::cout << "Span copy constructor called" << std::endl;
	this->_max = copy._max;
	this->_full = copy._full;
	this->_nums = copy._nums;
}

Span& Span::operator=( const Span& copy )
{
    std::cout << "Span copy assigment opperator called" << std::endl;
	if (this != &copy) {
		this->_max = copy._max;
		this->_full = copy._full;
		this->_nums = copy._nums;
	}
    return ( *this );
}

bool Span::getFull( void ) const
{
	return ( this->_full );
}

std::vector<int> Span::getNums( void ) const
{
	return ( this->_nums );
}

void Span::addNumber( int n )
{
	if (this->_full)
		throw Span::MaxStoredException();
	this->_nums.push_back(n);
	if (this->_nums.size() == this->_max)
		this->_full = true;
}

int Span::shortestSpan( void )
{
    if (this->_nums.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

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

int	Span::longestSpan( void )
{
	if (this->_nums.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int>::const_iterator itMin = std::min_element(this->_nums.begin(), this->_nums.end());
    std::vector<int>::const_iterator itMax = std::max_element(this->_nums.begin(), this->_nums.end());

    return ( static_cast<long long>(*itMax) - static_cast<long long>(*itMin) );
}

Span::~Span( void )
{
	std::cout << "Span Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
	for (size_t i = 0; i < span.getNums().size(); i++)
   		os << "Position "<< i << ": " << span.getNums().at(i) << std::endl;
    return os;
}