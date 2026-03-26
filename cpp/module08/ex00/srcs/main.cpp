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

#include <iostream>
#include <easyfind.hpp>
#include <vector>
#include <list>
#include <deque>

int main( void )
{
	std::cout << "=== Test 1: Vector with powers of 2 ===" << std::endl;
	std::vector<int> nums;
	for (int i = 1; i <= 100; i = i * 2)
		nums.push_back(i);
	try {
		std::vector<int>::iterator find = ::easyfind(nums, 32);
		std::cout << "Found in vector: " << *find << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 2: Const vector - value not found ===" << std::endl;
	const std::vector<int> cnums(nums.begin(), nums.end());
    try {
        std::vector<int>::const_iterator cit = ::easyfind(cnums, 30);
        std::cout << "Found in const vector: " << *cit << std::endl;
    } catch (std::exception &e) {
        std::cout << "Const search error: " << e.what() << std::endl;
    }
	
	std::cout << "\n=== Test 3: Vector with sequential numbers ===" << std::endl;
	std::vector<int> sequential;
	for (int i = 0; i < 10; i++)
		sequential.push_back(i);
	try {
		std::vector<int>::iterator it = ::easyfind(sequential, 5);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 4: List with integers ===" << std::endl;
	std::list<int> mylist;
	for (int i = 1; i <= 5; i++)
		mylist.push_back(i * 10);
	try {
		std::list<int>::iterator it = ::easyfind(mylist, 30);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 5: Deque - value not found ===" << std::endl;
	std::deque<int> mydeque;
	for (int i = 100; i < 105; i++)
		mydeque.push_back(i);
	try {
		std::deque<int>::iterator it = ::easyfind(mydeque, 99);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Deque search error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 6: Vector with negative numbers ===" << std::endl;
	std::vector<int> negative;
	for (int i = -5; i <= 5; i++)
		negative.push_back(i);
	try {
		std::vector<int>::iterator it = ::easyfind(negative, -3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}