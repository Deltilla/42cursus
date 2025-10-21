/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/21 17:52:38 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <easyfind.hpp>
#include <vector>

int main( void )
{
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
	const std::vector<int> cnums(nums.begin(), nums.end());
    try {
        std::vector<int>::const_iterator cit = ::easyfind(cnums, 30);
        std::cout << "Found in const vector: " << *cit << std::endl;
    } catch (std::exception &e) {
        std::cout << "Const search error: " << e.what() << std::endl;
    }
}