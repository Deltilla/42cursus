/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:16 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/24 19:22:24 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>

template<typename T, class Container>
MutantStack<T, Container>::MutantStack( void )  : std::stack<T, Container>()
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T, class Container>
MutantStack<T, Container>::MutantStack( const MutantStack& copy ) : std::stack<T, Container>(copy)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template<typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=( const MutantStack& copy )
{
    std::stack<T, Container>::operator=(copy);
    return *this;
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin( void )
{
	return ( this->c.begin() );
}

template<typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end( void )
{
	return ( this->c.end() );
}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack( void )
{
	std::cout << "MutantStack Destructor called" << std::endl;
}