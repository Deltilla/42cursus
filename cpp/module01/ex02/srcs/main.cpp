/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/08/07 18:20:51 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void )
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << &brain << std::endl
			<< &stringPTR << std::endl
			<< &stringREF << std::endl;
			
	std::cout << brain << std::endl
			<< stringPTR << std::endl
			<< stringREF << std::endl;
}