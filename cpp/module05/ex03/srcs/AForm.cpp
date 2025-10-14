/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:51:49 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 18:36:20 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>
#include <Bureaucrat.hpp>

AForm::AForm( void ) : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm( const std::string& name, const int signGrade, const int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Name assigment constructor called" << std::endl;
	if (this->_signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_signGrade > 150)
		throw AForm::GradeTooLowException();
	if (this->_executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const char* name, const int signGrade, const int executeGrade) : _name(name ? name : "Default"),  _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Name assigment constructor called" << std::endl;
	if (this->_signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_signGrade > 150)
		throw AForm::GradeTooLowException();
	if (this->_executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& copy) : _name(copy.getName()), _signed(copy.getSigned()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm& AForm::operator=( const AForm& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy)
		this->_signed = copy.getSigned();
    return ( *this );
}

std::string AForm::getName( void ) const
{
	return ( this->_name );
}

int AForm::getSignGrade( void ) const
{
	return ( this->_signGrade );
}

int AForm::getExecuteGrade( void ) const
{
	return ( this->_executeGrade );
}

bool AForm::getSigned( void ) const
{
	return( this->_signed );
}


void AForm::beSigned( Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->_signed = true;
	else if (bureaucrat.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}