/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:06:10 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/24 17:11:38 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat( void )
{
	std::cout << "Cat's default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat& copy)
{
	std::cout << "Cat's copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=( const Cat& copy )
{
    std::cout << "Cat's copy assigment opperator called" << std::endl;
    if (this != &copy)
		this->_type = copy.getType();
    return (*this);
}

Cat::Cat( std::string type )
{
    std::cout << "Cat's Name assigment constructor called" << std::endl;
    this->_type = type;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called" << std::endl;
	delete this->_brain;
}