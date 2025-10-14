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
#include <Intern.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main( void )
{
	try {
		
		Intern 		someRandom;
		AForm		*scf = someRandom.makeForm("shrubbery creation", "pito");
		Bureaucrat rodolfo("Rodolfo", 2);
		std::cout << rodolfo.getName() << ", bureaucrat grade "  << rodolfo.getGrade() << std::endl;
		rodolfo.improveGrade();
		std::cout << rodolfo.getName() << ", bureaucrat grade "  << rodolfo.getGrade() << std::endl;
		rodolfo.signForm(*scf);
		rodolfo.executeForm(*scf);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		
		Intern 		someRandom;
		AForm		*rrf = someRandom.makeForm("robotomy request", "pito");
		Bureaucrat carlos("carlos", 2);
		std::cout << carlos.getName() << ", bureaucrat grade "  << carlos.getGrade() << std::endl;
		carlos.improveGrade();
		std::cout << carlos.getName() << ", bureaucrat grade "  << carlos.getGrade() << std::endl;
		carlos.signForm(*rrf);
		carlos.executeForm(*rrf);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		
		Intern 		someRandom;
		AForm		*ppf = someRandom.makeForm("presidential pardon", "pito");
		Bureaucrat Ana("Ana", 2);
		std::cout << Ana.getName() << ", bureaucrat grade "  << Ana.getGrade() << std::endl;
		Ana.improveGrade();
		std::cout << Ana.getName() << ", bureaucrat grade "  << Ana.getGrade() << std::endl;
		Ana.signForm(*ppf);
		Ana.executeForm(*ppf);
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}