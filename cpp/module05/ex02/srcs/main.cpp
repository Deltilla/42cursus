/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 20:13:20 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main( void )
{
	try {
		
		Bureaucrat rodolfo("Rodolfo", 2);
		ShrubberyCreationForm		formulario("hola");
		std::cout << rodolfo.getName() << ", bureaucrat grade "  << rodolfo.getGrade() << std::endl;
		rodolfo.improveGrade();
		std::cout << rodolfo.getName() << ", bureaucrat grade "  << rodolfo.getGrade() << std::endl;
		rodolfo.signForm(formulario);
		rodolfo.executeForm(formulario);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		
		Bureaucrat carlos("carlos", 2);
		RobotomyRequestForm		formulario("Peter");
		std::cout << carlos.getName() << ", bureaucrat grade "  << carlos.getGrade() << std::endl;
		carlos.improveGrade();
		std::cout << carlos.getName() << ", bureaucrat grade "  << carlos.getGrade() << std::endl;
		carlos.signForm(formulario);
		carlos.executeForm(formulario);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		
		Bureaucrat Ana("Ana", 2);
		PresidentialPardonForm		formulario("Peter");
		std::cout << Ana.getName() << ", bureaucrat grade "  << Ana.getGrade() << std::endl;
		Ana.improveGrade();
		std::cout << Ana.getName() << ", bureaucrat grade "  << Ana.getGrade() << std::endl;
		Ana.signForm(formulario);
		Ana.executeForm(formulario);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}