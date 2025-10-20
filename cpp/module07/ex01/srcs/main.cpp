/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/20 12:21:41 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iter.hpp>

template<typename T>
void print_const_ref(const T &x) { std::cout << x << '\n'; }
template<typename T>
void increment(T &x) { x += 1; }

int main() {
    int nums[] = {1, 2, 3, 4};
	::iter(nums, 4u, print_const_ref<int>);
	::iter(nums, 4u, increment<int>);
	::iter(nums, 4u, print_const_ref<int>);
	
    std::string strs[] = {"one", "two", "three"};
    ::iter(strs, 3u, print_const_ref<std::string>);

    return 0;
}