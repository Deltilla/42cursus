/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:31:41 by analba-s          #+#    #+#             */
/*   Updated: 2025/07/11 14:09:06 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Provides essential functions for input and output operations. cin for input, cout for output, cerr for error output, endl for newlines and flush for flushing the output buffer. 
#include <cctype> // Provides functions to manipulate characters

int main(int arc, char **arv)
{
	std::string str;
	std::string::size_type i;

	if (arc == 2)
	{
		str = arv[1];
		i = -1;
		while (++i < str.size())
			str[i] = toupper(str[i]);
		std::cout << str << std::endl;
	}
}