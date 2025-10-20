/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/20 10:13:28 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main( void )
{
	try {
		
		Bureaucrat rodolfo("Rodolfo", 150);
		std::cout << rodolfo << std::endl;
		rodolfo.improveGrade();
		std::cout << rodolfo << std::endl;
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat carlos("Carlos", 1);
		std::cout << carlos << std::endl;
		carlos.worsenGrade();
		std::cout << carlos << std::endl;
	}
	catch ( const Bureaucrat::GradeTooLowException &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat ana("Ana", 1);
		std::cout << ana << std::endl;
		ana.improveGrade();
		std::cout << ana << std::endl;
	}
	catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}