/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/20 18:45:29 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

int main()
{
	
	
	try {
		Array<int> nums(4u);
		for (size_t i = 0; i < 4u; i++) {
			std::cout << i << std::endl;
			nums[i] = i;
			std::cout << nums[i] << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Array<std::string> str(3);
		
		str[0] = "Holi";
		str[1] = "wenas";
		str[2] = "tardes";
		for (int i = 0; i < 3; i++)
		std::cout << str[i] << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    return 0;
}