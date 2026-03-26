/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 10:49:18 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

int main( void )
{
	std::cout << "=== Test 1: Large Span with sequential numbers ===" << std::endl;
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
	
	std::cout << "\n=== Test 2: Span with powers of 2 ===" << std::endl;
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
	
	std::cout << "\n=== Test 3: Span with range -50 to 50 ===" << std::endl;
	try {
		Span nums(100u);
		nums.addNumber(-50, 50);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span: " << nums.longestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 4: Span with only 2 elements ===" << std::endl;
	try {
		Span nums(2u);
		nums.addNumber(5);
		nums.addNumber(10);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span: " << nums.longestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 5: Span - trying to add to full span ===" << std::endl;
	try {
		Span nums(3u);
		nums.addNumber(1);
		nums.addNumber(2);
		nums.addNumber(3);
		nums.addNumber(4);
	}
	catch ( std::exception &e) {
		std::cout << "Error (expected): " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 6: Span with only 1 element (should fail) ===" << std::endl;
	try {
		Span nums(5u);
		nums.addNumber(42);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cout << "Error (expected): " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 7: Span with identical numbers ===" << std::endl;
	try {
		Span nums(5u);
		for (int i = 0; i < 5; i++)
			nums.addNumber(7);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span: " << nums.longestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 8: Span with negative numbers ===" << std::endl;
	try {
		Span nums(10u);
		nums.addNumber(-100);
		nums.addNumber(-50);
		nums.addNumber(0);
		nums.addNumber(50);
		nums.addNumber(100);
		std::cout << "Shortest span: " << nums.shortestSpan() << std::endl;
		std::cout << "Longest span: " << nums.longestSpan() << std::endl;
	}
	catch ( std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}