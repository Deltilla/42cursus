/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:06:09 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 20:08:09 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm( void )
{
	std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm( "PresidentialPardonForm", 25, 5 )
{
	std::cout << "Name assigment constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm( copy.getName(), copy.getSignGrade(), copy.getExecuteGrade() )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_target = copy.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy) {
		this->_target = copy.getTarget();
	}
    return ( *this );
}

std::string PresidentialPardonForm::getTarget( void ) const
{
	return ( this->_target );
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecuteGrade())
			presidentialPardon( this->_target );
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called" << std::endl;
}

void	presidentialPardon( std::string target )
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}