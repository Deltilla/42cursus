/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/20 12:37:17 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <iostream>

template <typename T>
class Array
{
	public:
	
		Array();
		Array( unsigned int n );
	    ~Array();
	    Array( const Array& other );
	    Array& operator=( const Array& other );
		Array& operator[]( const Array& array);
	
	private:
		
		T *_array;
};
	

#endif