/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/20 18:33:11 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
	public:
	
		Array();
		Array( unsigned int n );
	    Array( const Array& copy );
	    Array& operator=( const Array& copy );
	    ~Array();

		T& operator[]( size_t i );

		size_t size( void );
	
	private:
		
		T*		_array;
		size_t	_size;
};

# include "../srcs/Array.tpp"

#endif