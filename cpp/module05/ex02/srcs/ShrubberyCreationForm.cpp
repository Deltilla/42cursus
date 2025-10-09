/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:04:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 19:56:48 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm( void )
{
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm( "ShrubberyCreationForm", 145, 137 )
{
	std::cout << "Name assigment constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm( copy.getName(), copy.getSignGrade(), copy.getExecuteGrade() )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_target = copy.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy) {
		this->_target = copy.getTarget();
	}
    return ( *this );
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return ( this->_target );
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecuteGrade())
			shrubberyCreation( this->_target );
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}

void	shrubberyCreation( std::string target )
{
	std::ofstream of(target.c_str(), std::ios_base::out);
	int	leafSpaceWidth = 42;
	int	trunkWidth = 4;
	if (!of.is_open())
		std::cout << "error: Could not create the replace file" << std::endl;
	for (int i = 0; i < 5; ++i) {
		for (int l = 1; l < leafSpaceWidth / 2; l += 2) {
			for (int i = 0; i < (leafSpaceWidth / 2) - l; ++i)
				of << " ";
			for (int leafs = l; leafs > 0; leafs--)
				of << "*";
			for (int leafs = l; leafs > 0; leafs--)
				of << "*";
			for (int i = 0; i < (leafSpaceWidth / 2) - l; ++i)
				of << " ";
			of << std::endl;
		for (int i = 0; i < (leafSpaceWidth / 2) - 2; ++i)
				of << " ";
		for (int t = 0; t < trunkWidth; t++)
				of << "*";
		for (int i = 0; i < (leafSpaceWidth / 2) - l; ++i)
				of << " ";
		of << std::endl;
		}
		of << std::endl;
	}
	of.close();
}