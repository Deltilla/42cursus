/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:01:25 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/06 20:36:10 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data {
    std::string name;
    int value;
    bool isActive;

    void display() const {
        std::cout << "--- Data Content ---" << std::endl;
        std::cout << "Name:     " << name << std::endl;
        std::cout << "Value:    " << value << std::endl;
        std::cout << "Active:   " << (isActive ? "Yes" : "No") << std::endl;
        std::cout << "--------------------" << std::endl;
    }
};

#endif