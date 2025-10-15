/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:51:49 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/15 18:34:30 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <iostream>

Intern::Intern( void )
{
	std::cout << "Default constructor called" << std::endl;
    this->forms[0] = &Intern::_createShrubberyCreation;
    this->forms[1] = &Intern::_createRobotomyRequest;
    this->forms[2] = &Intern::_createPresidentialPardon;
}

Intern::Intern( const Intern& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->forms[0] = copy.forms[0];
	this->forms[1] = copy.forms[1];
	this->forms[2] = copy.forms[2];
}

Intern& Intern::operator=( const Intern& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy) {
		this->forms[0] = copy.forms[0];
		this->forms[1] = copy.forms[1];
		this->forms[2] = copy.forms[2];
	}
    return ( *this );
}

AForm* Intern::_createRobotomyRequest( const std::string& target )
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::_createPresidentialPardon( const std::string& target )
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::_createShrubberyCreation( const std::string& target )
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm( const std::string& formName, const std::string& target )
{
	const std::string formNames[3] = {
    	"shrubbery creation",
		"robotomy request",
    	"presidential pardon",
	};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            AForm* form = (this->*forms[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
	throw Intern::FormIsUnknownException(formName);
}

Intern::~Intern()
{
	std::cout << "Destructor called" << std::endl;
}