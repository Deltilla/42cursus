/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/09 16:43:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <cstdlib> // Needed for strtod

// --- Constructor y Operadores (para asegurar la no-instanciabilidad) ---

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

// --- Helper Functions for Type Detection ---

bool ScalarConverter::isCharLiteral(const std::string& s) {
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

bool ScalarConverter::isIntLiteral(const std::string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '+' || s[0] == '-') start = 1;
    if (start == s.length()) return false;

    for (size_t i = start; i < s.length(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}

/**
 * @brief Verifica si una cadena representa un literal float (e.g., 4.2f, nanf).
 */
bool ScalarConverter::isFloatLiteral(const std::string& s) {
    if (s.empty()) return false;
    std::string lower_s = s;
    std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

    // Pseudo-literales de float
    if (lower_s == "-inff" || lower_s == "+inff" || lower_s == "nanf") {
        return true;
    }

    // *** CORRECCIÓN: Usar índice manual en lugar de back() ***
    // Debe terminar en 'f' y contener un '.'
    if (lower_s.length() < 2 || lower_s[lower_s.length() - 1] != 'f' || lower_s.find('.') == std::string::npos) {
        return false;
    }

    // Verifica que la parte numérica sin la 'f' sea un double válido
    std::string num_part = lower_s.substr(0, lower_s.length() - 1);
    
    // Check for signs
    size_t start = 0;
    if (num_part[0] == '+' || num_part[0] == '-') start = 1;

    int dot_count = 0;
    bool has_digits = false;
    for (size_t i = start; i < num_part.length(); ++i) {
        if (num_part[i] == '.') {
            dot_count++;
        } else if (!std::isdigit(num_part[i])) {
            return false;
        } else {
            has_digits = true;
        }
    }
    return dot_count == 1 && has_digits;
}

/**
 * @brief Verifica si una cadena representa un literal double (e.g., 4.2, nan).
 */
bool ScalarConverter::isDoubleLiteral(const std::string& s) {
    if (s.empty()) return false;
    std::string lower_s = s;
    std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

    // Pseudo-literales de double
    if (lower_s == "-inf" || lower_s == "+inf" || lower_s == "nan") {
        return true;
    }

    // Debe contener un '.'
    if (lower_s.find('.') == std::string::npos) {
        return false;
    }

    // Verifica que la parte numérica sea un double válido
    size_t start = 0;
    if (lower_s[0] == '+' || lower_s[0] == '-') start = 1;

    int dot_count = 0;
    bool has_digits = false;
    for (size_t i = start; i < lower_s.length(); ++i) {
        if (lower_s[i] == '.') {
            dot_count++;
        } else if (!std::isdigit(lower_s[i])) {
            return false;
        } else {
            has_digits = true;
        }
    }

    return dot_count == 1 && has_digits;
}

// --- Conversion and Display Functions ---

void ScalarConverter::displayConversions(double d) {
    std::cout << std::fixed << std::setprecision(1);

    // 1. Conversión a char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(c)) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    }

    // 2. Conversión a int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        int i = static_cast<int>(d);
        std::cout << i << std::endl;
    }

    // 3. Conversión a float
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (std::isinf(f) && !std::isinf(d) && !std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    } else {
        if (std::isnan(f)) std::cout << "nanf" << std::endl;
        else if (std::isinf(f)) std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
        else std::cout << f << "f" << std::endl;
    }

    // 4. Conversión a double
    std::cout << "double: ";
    if (std::isnan(d)) std::cout << "nan" << std::endl;
    else if (std::isinf(d)) std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    else std::cout << d << std::endl;
}

// --- Public Static Method ---

/**
 * @brief Convierte un literal string a char, int, float y double.
 */
void ScalarConverter::convert(const std::string& s) {
    if (s.empty()) {
        std::cerr << "Error: Input string is empty." << std::endl;
        return;
    }

    double d = 0.0;
    bool conversion_success = true;

    // 1. Detección y conversión a double
    if (isCharLiteral(s)) {
        d = static_cast<double>(s[1]);
    } else if (isIntLiteral(s)) {
        // *** CORRECCIÓN: Usar strtod para compatibilidad ***
        char *endptr;
        d = std::strtod(s.c_str(), &endptr);
        // Verificar si la conversión fue completa y si hubo overflow
        if (*endptr != '\0' || s.c_str() == endptr || std::isinf(d)) {
            conversion_success = false;
        }
    } else if (isFloatLiteral(s)) {
        std::string s_no_f = s.substr(0, s.length() - 1);
        
        // *** CORRECCIÓN: Usar strtod para compatibilidad, luego castear a float ***
        char *endptr;
        double temp_d = std::strtod(s_no_f.c_str(), &endptr);
        if (*endptr != '\0' || s_no_f.c_str() == endptr) {
            // Manejar pseudo-literales si falló la conversión numérica (ya que strtod
            // maneja inf/nan, esto captura errores de formato o overflow extremos)
            std::string lower_s = s;
            std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
            if (lower_s == "-inff") d = -std::numeric_limits<double>::infinity();
            else if (lower_s == "+inff") d = std::numeric_limits<double>::infinity();
            else if (lower_s == "nanf") d = std::numeric_limits<double>::quiet_NaN();
            else conversion_success = false;
        } else {
            d = temp_d;
        }
    } else if (isDoubleLiteral(s)) {
        // *** CORRECCIÓN: Usar strtod para compatibilidad ***
        char *endptr;
        d = std::strtod(s.c_str(), &endptr);
        if (*endptr != '\0' || s.c_str() == endptr) {
            // Manejar pseudo-literales si falló la conversión numérica
            std::string lower_s = s;
            std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
            if (lower_s == "-inf") d = -std::numeric_limits<double>::infinity();
            else if (lower_s == "+inf") d = std::numeric_limits<double>::infinity();
            else if (lower_s == "nan") d = std::numeric_limits<double>::quiet_NaN();
            else conversion_success = false;
        }
    } else {
        // Tipo de literal desconocido o inválido
        conversion_success = false;
    }

    // 2. Mostrar Resultados
    if (conversion_success) {
        displayConversions(d);
    } else {
        std::cout << "Error: Invalid literal or conversion impossible/overflowed during parsing." << std::endl;
    }
}