/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/24 12:22:52 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

int main( void )
{
	try {
		Span nums(100000u);
		for (int i = 1; nums.getFull() == false; i++)
			nums.addNumber(i);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span: " << nums.longestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span nums(100u);
		for (int i = 1; nums.getFull() == false; i = i * 2)
			nums.addNumber(i);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span: " << nums.longestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span nums(100u);
		nums.addNumber(-50, 50);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span: " << nums.longestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}