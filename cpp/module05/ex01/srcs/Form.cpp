/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:51:49 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/06 20:41:01 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form( void ) : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form( const std::string& name, const int signGrade, const int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Name assigment constructor called" << std::endl;
	if (this->_signGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_signGrade > 150)
		throw Form::GradeTooLowException();
	if (this->_executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const char* name, const int signGrade, const int executeGrade) : _name(name ? name : "Default"),  _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Name assigment constructor called" << std::endl;
	if (this->_signGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_signGrade > 150)
		throw Form::GradeTooLowException();
	if (this->_executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form& copy) : _name(copy.getName()), _signed(copy.getSigned()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	std::cout << "Copy constructor called" << std::endl;
}

Form& Form::operator=( const Form& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy)
		this->_signed = copy.getSigned();
    return ( *this );
}

std::string Form::getName( void ) const
{
	return ( this->_name );
}

int Form::getSignGrade( void ) const
{
	return ( this->_signGrade );
}

int Form::getExecuteGrade( void ) const
{
	return ( this->_executeGrade );
}

bool Form::getSigned( void ) const
{
	return( this->_signed );
}

void Form::beSigned( Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->_signed = true;
	else if (bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}