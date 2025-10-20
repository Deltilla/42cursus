/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/20 10:25:41 by analba-s         ###   ########.fr       */
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
		std::cout << rodolfo << std::endl;
		rodolfo.improveGrade();
		std::cout << rodolfo << std::endl;
		rodolfo.signForm(formulario);
		rodolfo.executeForm(formulario);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		
		Bureaucrat carlos("carlos", 2);
		RobotomyRequestForm		formulario("Peter");
		std::cout << carlos << std::endl;
		carlos.improveGrade();
		std::cout << carlos << std::endl;
		carlos.signForm(formulario);
		carlos.executeForm(formulario);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		
		Bureaucrat Ana("Ana", 2);
		PresidentialPardonForm		formulario("Peter");
		std::cout << Ana << std::endl;
		Ana.improveGrade();
		std::cout << Ana << std::endl;
		Ana.signForm(formulario);
		Ana.executeForm(formulario);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}