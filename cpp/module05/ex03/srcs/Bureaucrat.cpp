/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/15 17:48:15 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <AForm.hpp>

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade)
{
	std::cout << "Name assigment constructor called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const char* name, int grade ) : _name(name ? name : "Default"), _grade(grade)
{
	std::cout << "Name assigment constructor called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy)
		this->_grade = copy.getGrade();
    return ( *this );
}

const std::string Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

int Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void Bureaucrat::setGrade( int grade )
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

void Bureaucrat::improveGrade( void )
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::worsenGrade( void )
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm( AForm& form )
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " <<  form.getName() << std::endl;
	}
	catch ( const AForm::GradeTooLowException &e ) {
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const & form ) const
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " <<  form.getName() << std::endl;
	}
	catch ( const AForm::GradeTooLowException &e ) {
		std::cerr << this->getName() << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
