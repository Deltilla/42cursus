/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/16 19:13:45 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <cstdlib>


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral( const std::string& s )
{
    return ( s.length() == 3 && s[0] == '\'' && s[2] == '\'' );
}

bool ScalarConverter::isIntLiteral( const std::string& s )
{
    if (s.empty())
		return ( false );
    size_t start = 0;
    if (s[0] == '+' || s[0] == '-')
		start = 1;
    if (start == s.length())
		return ( false );
    for (size_t i = start; i < s.length(); ++i) {
        if (!std::isdigit(s[i]))
			return ( false );
    }
    return ( true );
}

bool ScalarConverter::isFloatLiteral( const std::string& s )
{
    if (s.empty())
		return ( false );
    std::string lower_s = s;
    std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
    if (lower_s == "-inff" || lower_s == "+inff" || lower_s == "nanf")
        return ( true );
    if (lower_s.length() < 2 || lower_s[lower_s.length() - 1] != 'f' || lower_s.find('.') == std::string::npos)
        return ( false );
    std::string num_part = lower_s.substr(0, lower_s.length() - 1);
    size_t start = 0;
    if (num_part[0] == '+' || num_part[0] == '-')
		start = 1;
    int dot_count = 0;
    bool has_digits = false;
    for (size_t i = start; i < num_part.length(); ++i) {
        if (num_part[i] == '.')
            dot_count++;
        else if (!std::isdigit(num_part[i]))
            return ( false );
        else
            has_digits = true;
    }
    return ( dot_count == 1 && has_digits );
}

bool ScalarConverter::isDoubleLiteral( const std::string& s )
{
    if (s.empty())
		return false;
    std::string lower_s = s;
    std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
    if (lower_s == "-inf" || lower_s == "+inf" || lower_s == "nan")
        return ( true );
    if (lower_s.find('.') == std::string::npos)
        return ( false );
    size_t start = 0;
    if (lower_s[0] == '+' || lower_s[0] == '-')
		start = 1;
    int dot_count = 0;
    bool has_digits = false;
    for (size_t i = start; i < lower_s.length(); ++i) {
        if (lower_s[i] == '.')
            dot_count++;
        else if (!std::isdigit(lower_s[i]))
            return ( false );
        else
            has_digits = true;
    }

    return ( dot_count == 1 && has_digits );
}
void ScalarConverter::displayConversions( double d )
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else {
        char c = static_cast<char>(d);
        if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else {
        int i = static_cast<int>(d);
        std::cout << i << std::endl;
    }
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (std::isinf(f) && !std::isinf(d) && !std::isnan(d))
        std::cout << "impossible" << std::endl;
    else {
        if (std::isnan(f))
			std::cout << "nanf" << std::endl;
        else if (std::isinf(f))
			std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
        else
			std::cout << f << "f" << std::endl;
    }
    std::cout << "double: ";
    if (std::isnan(d))
		std::cout << "nan" << std::endl;
    else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
		std::cout << d << std::endl;
}

void ScalarConverter::convert( const std::string& s )
{
    if (s.empty()) {
        std::cerr << "Error: Input string is empty." << std::endl;
        return ;
    }
    double d = 0.0;
    bool conversion_success = true;
    if (isCharLiteral(s))
        d = static_cast<double>(s[1]);
	else if (isIntLiteral(s)) {
        char *endptr;
        d = std::strtod(s.c_str(), &endptr);
        if (*endptr != '\0' || s.c_str() == endptr || std::isinf(d))
            conversion_success = false;
    }
	else if (isFloatLiteral(s)) {
    	std::string s_no_f = s.substr(0, s.length() - 1);
    	char *endptr;
    	double temp_d = std::strtod(s_no_f.c_str(), &endptr);
    	if (*endptr != '\0' || s_no_f.c_str() == endptr) {
    	    std::string lower_s = s;
    	    std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
    	    if (lower_s == "-inff")
				d = -std::numeric_limits<double>::infinity();
    	    else if (lower_s == "+inff")
				d = std::numeric_limits<double>::infinity();
    	    else if (lower_s == "nanf")
				d = std::numeric_limits<double>::quiet_NaN();
    	    else
				conversion_success = false;
		}
		else
        	d = temp_d;
    }
    else if (isDoubleLiteral(s)) {
        char *endptr;
        d = std::strtod(s.c_str(), &endptr);
        if (*endptr != '\0' || s.c_str() == endptr) {
            std::string lower_s = s;
            std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
            if (lower_s == "-inf") d = -std::numeric_limits<double>::infinity();
            else if (lower_s == "+inf") d = std::numeric_limits<double>::infinity();
            else if (lower_s == "nan") d = std::numeric_limits<double>::quiet_NaN();
            else conversion_success = false;
        }
    }
	else
        conversion_success = false;
    if (conversion_success)
        displayConversions(d);
	else
        std::cout << "Error: Invalid literal or conversion impossible/overflowed during parsing." << std::endl;
}