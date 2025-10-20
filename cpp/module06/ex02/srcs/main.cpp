/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/17 20:17:47 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Test 1: Random generation ===" << std::endl;
    {
        Base* random = generate();
        std::cout << "Identified by pointer: ";
        identify(random);
        std::cout << "Identified by reference: ";
        identify(*random);
        delete random;
    }

    std::cout << "\n=== Test 2: All specific types ===" << std::endl;
    {
        std::cout << "\n--- Testing A ---" << std::endl;
        Base* a = new A();
        std::cout << "By pointer: ";
        identify(a);
        std::cout << "By reference: ";
        identify(*a);
        delete a;

        std::cout << "\n--- Testing B ---" << std::endl;
        Base* b = new B();
        std::cout << "By pointer: ";
        identify(b);
        std::cout << "By reference: ";
        identify(*b);
        delete b;

        std::cout << "\n--- Testing C ---" << std::endl;
        Base* c = new C();
        std::cout << "By pointer: ";
        identify(c);
        std::cout << "By reference: ";
        identify(*c);
        delete c;
    }

    std::cout << "\n=== Test 3: Multiple generations ===" << std::endl;
    {
        for (int i = 0; i < 5; i++) {
            std::cout << "\nGeneration " << i + 1 << ":" << std::endl;
            Base* obj = generate();
            std::cout << "  Pointer: ";
            identify(obj);
            std::cout << "  Reference: ";
            identify(*obj);
            delete obj;
        }
    }

    std::cout << "\n=== Test 4: Array of bases ===" << std::endl;
    {
        Base* bases[6];
        bases[0] = new A();
        bases[1] = new B();
        bases[2] = new C();
        bases[3] = new A();
        bases[4] = new B();
        bases[5] = new C();

        std::cout << "Array contents:" << std::endl;
        for (int i = 0; i < 6; i++) {
            std::cout << "  [" << i << "] Ptr: ";
            identify(bases[i]);
            std::cout << "      Ref: ";
            identify(*bases[i]);
        }

        for (int i = 0; i < 6; i++)
            delete bases[i];
    }

    std::cout << "\n=== Test 5: Base pointer to Base ===" << std::endl;
    {
        std::cout << "Testing polymorphism:" << std::endl;
        Base* polyA = new A();
        Base* polyB = new B();
        Base* polyC = new C();

        std::cout << "PolyA: "; identify(polyA);
        std::cout << "PolyB: "; identify(polyB);
        std::cout << "PolyC: "; identify(polyC);

        delete polyA;
        delete polyB;
        delete polyC;
    }

    std::cout << "\n=== Test 6: Consistency check ===" << std::endl;
    {
        std::cout << "Verifying pointer and reference give same result:" << std::endl;
        for (int i = 0; i < 3; i++) {
            Base* obj = generate();
            std::cout << "  Attempt " << i + 1 << " - Ptr: ";
            identify(obj);
            std::cout << "                 Ref: ";
            identify(*obj);
            delete obj;
        }
    }

    std::cout << "\n=== Test 7: NULL pointer (edge case) ===" << std::endl;
    {
        Base* null = NULL;
        std::cout << "Identifying NULL pointer: ";
        identify(null);
    }

    return 0;
}