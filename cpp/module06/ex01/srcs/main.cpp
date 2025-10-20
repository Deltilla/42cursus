/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/17 20:25:15 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <Serializer.hpp>
#include <Data.hpp>
#include <iostream>
#include <iomanip>

void printData(const std::string& label, Data* data)
{
    std::cout << label << std::endl;
    std::cout << "  Address: " << data << std::endl;
    std::cout << "  Name: " << data->name << std::endl;
    std::cout << "  Grade: " << data->grade << std::endl;
}

int main( void )
{
	Data Peter;
	
	Peter.name = "Pedro";
	Peter.grade = 42;
	Peter.isActive = true;
	
	std::cout << "=== Test 0: Easy test ===" << std::endl;
    std::cout << "--- Data Content ---" << std::endl;
    std::cout << "Name:     " << Peter.name << std::endl;
    std::cout << "Grade:    " << Peter.grade << std::endl;
    std::cout << "Active:   " << (Peter.isActive ? "Yes" : "No") << std::endl;
    std::cout << "--------------------" << std::endl;
	
	std::cout << "Address before: " << &Peter << std::endl;
	std::cout << "Address after deserialize: " 
			<< Serializer::deserialize(Serializer::serialize(&Peter)) << std::endl;

    std::cout << "=== Test 1: Basic serialization ===" << std::endl;
    {
        Data original;
        original.name = "Test";
        original.grade = 42;

        printData("Original:", &original);

        uintptr_t raw = Serializer::serialize(&original);
        std::cout << "\nSerialized to: 0x" << std::hex << raw << std::dec << std::endl;

        Data* deserialized = Serializer::deserialize(raw);
        printData("\nDeserialized:", deserialized);

        std::cout << "\nPointers match: " 
                  << ((&original == deserialized) ? "✓ YES" : "✗ NO") << std::endl;
        std::cout << "Data intact: " 
                  << ((original.name == deserialized->name && 
                       original.grade == deserialized->grade) ? "✓ YES" : "✗ NO") 
                  << std::endl;
    }

    std::cout << "\n=== Test 2: Multiple serializations ===" << std::endl;
    {
        Data d1, d2, d3;
        d1.name = "First";  d1.grade = 1;
        d2.name = "Second"; d2.grade = 2;
        d3.name = "Third";  d3.grade = 3;

        uintptr_t r1 = Serializer::serialize(&d1);
        uintptr_t r2 = Serializer::serialize(&d2);
        uintptr_t r3 = Serializer::serialize(&d3);

        Data* p1 = Serializer::deserialize(r1);
        Data* p2 = Serializer::deserialize(r2);
        Data* p3 = Serializer::deserialize(r3);

        std::cout << "All pointers match: " 
                  << ((&d1 == p1 && &d2 == p2 && &d3 == p3) ? "✓ YES" : "✗ NO") 
                  << std::endl;
        std::cout << "All unique: " 
                  << ((p1 != p2 && p2 != p3 && p1 != p3) ? "✓ YES" : "✗ NO") 
                  << std::endl;
    }

    std::cout << "\n=== Test 3: Empty/default grades ===" << std::endl;
    {
        Data empty;
        empty.name = "";
        empty.grade = 0;

        uintptr_t raw = Serializer::serialize(&empty);
        Data* restored = Serializer::deserialize(raw);

        std::cout << "Empty string preserved: " 
                  << ((restored->name == "") ? "✓ YES" : "✗ NO") << std::endl;
        std::cout << "Zero grades preserved: " 
                  << ((restored->grade == 0) ? "✓ YES" : "✗ NO") 
                  << std::endl;
    }

    std::cout << "\n=== Test 4: Extreme grades ===" << std::endl;
    {
        Data extreme;
        extreme.name = "Very long string with many characters to test if serialization handles strings properly";
        extreme.grade = -2147483648; // INT_MIN

        uintptr_t raw = Serializer::serialize(&extreme);
        Data* restored = Serializer::deserialize(raw);

        printData("Extreme grades restored:", restored);
        std::cout << "Match: " << ((&extreme == restored) ? "✓ YES" : "✗ NO") << std::endl;
    }

    std::cout << "\n=== Test 5: Sequential operations ===" << std::endl;
    {
        Data data;
        data.name = "Sequential";
        data.grade = 100;

        uintptr_t r1 = Serializer::serialize(&data);
        Data* p1 = Serializer::deserialize(r1);
        
        uintptr_t r2 = Serializer::serialize(p1);
        Data* p2 = Serializer::deserialize(r2);
        
        uintptr_t r3 = Serializer::serialize(p2);
        Data* p3 = Serializer::deserialize(r3);

        std::cout << "All cycles point to same address: " 
                  << ((&data == p1 && p1 == p2 && p2 == p3) ? "✓ YES" : "✗ NO") 
                  << std::endl;
    }

    return 0;
}