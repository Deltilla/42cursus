/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:16 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 10:56:12 by analba-s         ###   ########.fr       */
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
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin( void ) const
{
	return ( this->c.begin() );
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end( void ) const
{
	return ( this->c.end() );
}

template<typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin( void )
{
	return ( this->c.rbegin() );
}

template<typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend( void )
{
	return ( this->c.rend() );
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin( void ) const
{
	return ( this->c.rbegin() );
}

template<typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend( void ) const
{
	return ( this->c.rend() );
}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack( void )
{
	std::cout << "MutantStack Destructor called" << std::endl;
}