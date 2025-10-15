/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:19:40 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/15 18:53:10 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm( void )
{
	std::cout << "Default constructor called" << std::endl;
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm( "RobotomyRequestForm", 72, 45 )
{
	std::cout << "Name assigment constructor called" << std::endl;
	srand(time(NULL));
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm( copy.getName(), copy.getSignGrade(), copy.getExecuteGrade() )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_target = copy.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& copy )
{
    std::cout << "Copy assigment opperator called" << std::endl;
	if (this != &copy) {
		this->_target = copy.getTarget();
	}
    return ( *this );
}

std::string RobotomyRequestForm::getTarget( void ) const
{
	return ( this->_target );
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecuteGrade())
			robotomyRequest( this->_target );
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSignedException(this->getName());
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called" << std::endl;
}

void	robotomyRequest( std::string target )
{
	int n = rand();
	std::cout << "Drilling noises..." << std::endl;
	if (n < RAND_MAX/2)
		std::cout << target << " has been robotomized succesfully (ㆆ _ ㆆ)" << std::endl;
	else
		std::cout << "robotomy failed succesfully (｡◕‿‿◕｡)" << std::endl;
}