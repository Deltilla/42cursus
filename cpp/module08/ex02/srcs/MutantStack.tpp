/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:16 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/24 12:35:24 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>

MutantStack::MutantStack( void )
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

MutantStack::MutantStack( unsigned int N )
{
	std::cout << "MutantStack assigment constructor called" << std::endl;
}

MutantStack::MutantStack( const MutantStack& copy )
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

MutantStack& MutantStack::operator=( const MutantStack& copy )
{
    std::cout << "MutantStack copy assigment opperator called" << std::endl;
	if (this != &copy) {
		
	}
    return ( *this );
}

MutantStack::~MutantStack( void )
{
	std::cout << "MutantStack Destructor called" << std::endl;
}