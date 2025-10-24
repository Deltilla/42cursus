/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/24 19:50:34 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>
#include <fstream>

int main( int arc, char** arv )
{
	if (arc == 2)
	{
		std::ifstream database("../data.csv", std::ios_base::in);
		if (!database.is_open())
            std::cerr << "error: Could not open the database" << std::endl;
		std::ifstream imput(arv[1], std::ios_base::in);
		if (!imput.is_open())
            std::cerr << "error: Could not open the file" << std::endl;
	}
}