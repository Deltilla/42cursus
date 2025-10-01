/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:06:10 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/01 11:59:41 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat( void )
{
	//std::cout << "Cat's default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( std::string type )
{
	//std::cout << "Cat's Type assigment constructor called" << std::endl;
	this->_type = type;
}

Cat::Cat( const Cat& copy )
{
	//std::cout << "Cat's copy constructor called" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(*copy._brain);
}

Cat& Cat::operator=( const Cat& copy )
{
    //std::cout << "Cat's copy assigment opperator called" << std::endl;
    if (this != &copy)
		this->_type = copy.getType();
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*copy._brain);
    return (*this);
}

void	setBrain( Brain brain )
{
	//std::cout << "Cat's setBrain member function called" << std::endl;
	this->_brain = &brain;
}

Cat::~Cat()
{
	//std::cout << "Cat's destructor called" << std::endl;
	delete this->_brain;
}