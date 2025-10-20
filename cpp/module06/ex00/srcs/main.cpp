/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/17 20:23:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return (1);
    }
	
	std::cout << "=== Test 0: Easy test ===" << std::endl;
	
    std::string literal = argv[1];
    std::cout << "Input literal: " << literal << std::endl;
    std::cout << "----------------------" << std::endl;

    ScalarConverter::convert(literal);

    std::cout << "----------------------" << std::endl;

	    std::cout << "=== Test 1: Input from user ===" << std::endl;
    ScalarConverter::convert(argv[1]);

    std::cout << "\n=== Test 2: Char literals ===" << std::endl;
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("'z'");
    ScalarConverter::convert("'0'");
    
    std::cout << "\n=== Test 3: Int literals ===" << std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("2147483647");
    ScalarConverter::convert("-2147483648");
    
    std::cout << "\n=== Test 4: Float literals ===" << std::endl;
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-42.42f");
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("nanf");
    
    std::cout << "\n=== Test 5: Double literals ===" << std::endl;
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("-42.42");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("nan");
    
    std::cout << "\n=== Test 6: Edge cases ===" << std::endl;
    ScalarConverter::convert("127");
    ScalarConverter::convert("128");
    ScalarConverter::convert("-128");
    ScalarConverter::convert("-129");
    
    std::cout << "\n=== Test 7: Non-displayable chars ===" << std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("9");
    ScalarConverter::convert("10");
    ScalarConverter::convert("31");
    ScalarConverter::convert("32");
    ScalarConverter::convert("126");
    ScalarConverter::convert("127");
    
    std::cout << "\n=== Test 8: Invalid inputs ===" << std::endl;
    ScalarConverter::convert("abc");
    ScalarConverter::convert("42.42.42");
    ScalarConverter::convert("42f42");
    ScalarConverter::convert("");
    ScalarConverter::convert("'ab'");
    
    return 0;
}
