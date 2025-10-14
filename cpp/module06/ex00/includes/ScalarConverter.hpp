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
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {

	private:

	    ScalarConverter();
	    ~ScalarConverter();
	    ScalarConverter( const ScalarConverter& other );
	    ScalarConverter& operator=( const ScalarConverter& other );

	    static bool isCharLiteral( const std::string& s );
	    static bool isIntLiteral( const std::string& s );
	    static bool isFloatLiteral( const std::string& s );
	    static bool isDoubleLiteral( const std::string& s );

	    static void displayConversions( double d );

	public:
	    static void convert( const std::string& s );

};

#endif