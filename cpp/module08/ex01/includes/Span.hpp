/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/24 12:26:33 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <stdexcept>
# include <iostream>
# include <limits>

class Span
{
	public:

    	Span();
		Span( unsigned int N );
    	Span(const Span& other);
		Span& operator=(const Span& other);
    	~Span();

		std::vector<int>	getNums( void ) const;
		bool				getFull( void ) const;

		
		void		addNumber( int n );
		int			shortestSpan( void );
		int			longestSpan( void );
		
		template <typename It>
		void		addNumber(It first, It last) {
			if (this->_full)
				throw Span::MaxStoredException();
			for (; this->_nums.size() != this->_max && first != last; first++)
				this->_nums.push_back(first);
			if (this->_nums.size() == this->_max)
				this->_full = true;
		}

		class MaxStoredException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ( "Span is already full" );
				}
		};

	private:

		std::vector<int>	_nums;
		unsigned int		_max;
		bool				_full;

};

std::ostream& operator<<(std::ostream& os, const Span& span);

#endif