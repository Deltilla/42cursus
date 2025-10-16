/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/16 19:56:41 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>
#include <Data.hpp>
#include <iostream>

int main( void )
{
	Data Peter;

	Peter.name = "Pedro";
	Peter.grade = 42;
	Peter.isActive = true;

    std::cout << "--- Data Content ---" << std::endl;
    std::cout << "Name:     " << Peter.name << std::endl;
    std::cout << "Value:    " << Peter.grade << std::endl;
    std::cout << "Active:   " << (Peter.isActive ? "Yes" : "No") << std::endl;
    std::cout << "--------------------" << std::endl;
	
	std::cout << "Address before: " << &Peter << std::endl;
	std::cout << "Address after deserialize: " << Serializer::deserialize(Serializer::serialize(&Peter)) << std::endl;
}