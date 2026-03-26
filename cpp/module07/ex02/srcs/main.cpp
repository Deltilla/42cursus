/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/11/04 18:07:35 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

int main()
{
    std::cout << "=== Test 1: Array<int> ===" << std::endl;
    try {
        Array<int> nums(4u);
        for (size_t i = 0; i < 4u; i++) {
            nums[i] = i;
            std::cout << nums[i] << std::endl;
        }
        std::cout << "Attempting to access out of bounds..." << std::endl;
        std::cout << nums[10] << std::endl;  // ❌ Lanzará excepción
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Array<std::string> ===" << std::endl;
    try {
        Array<std::string> str(3);
        
        str[0] = "Holi";
        str[1] = "wenas";
        str[2] = "tardes";
        for (size_t i = 0; i < 3; i++)
            std::cout << str[i] << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Empty Array ===" << std::endl;
    try {
        Array<std::string> str;
        std::cout << "Empty array size: " << str.size() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Out of Bounds Exception ===" << std::endl;
    try {
        Array<int> test(2);
        test[0] = 42;
        std::cout << "Valid access: " << test[0] << std::endl;
        std::cout << "Attempting invalid access..." << std::endl;
        std::cout << test[5] << std::endl;  // ❌ Excepción
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}