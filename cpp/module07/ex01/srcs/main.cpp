/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/11/04 18:02:59 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iter.hpp>

template<typename T>
void print_const_ref(const T &x) { std::cout << x << '\n'; }

template<typename T>
void increment(T &x) { x += 1; }


template<typename T>
void print_address(T &x) { std::cout << "&" << &x << " "; }

int main()
{
    std::cout << "=== Test 1: Integer Array (non-const) ===" << std::endl;
    {
        int nums[] = {1, 2, 3, 4, 5};
        
        std::cout << "Original: ";
        ::iter(nums, 5, print_const_ref<int>);
        std::cout << std::endl;
        
        ::iter(nums, 5, increment<int>);
        
        std::cout << "After increment: ";
        ::iter(nums, 5, print_const_ref<int>);
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 2: String Array (non-const) ===" << std::endl;
    {
        std::string strs[] = {"Hello", "World", "C++"};
        
        std::cout << "Strings: ";
        ::iter(strs, 3, print_const_ref<std::string>);
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 3: Float Array (const reference) ===" << std::endl;
    {
        const float floats[] = {1.5f, 2.7f, 3.14f};
        
        std::cout << "Floats: ";
        ::iter(floats, 3, print_const_ref<float>);
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 4: Const Integer Array ===" << std::endl;
    {
        const int const_nums[] = {10, 20, 30};
        
        std::cout << "Const integers: ";
        ::iter(const_nums, 3, print_const_ref<int>);
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 5: Double Array with Custom Function ===" << std::endl;
    {
        double values[] = {1.1, 2.2, 3.3};
        
        std::cout << "Addresses: ";
        ::iter(values, 3, print_address<double>);
        std::cout << std::endl;
    }

    return 0;
}