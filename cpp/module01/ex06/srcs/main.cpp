/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/09/24 13:30:24 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

void	checkComplains(Harl harl, char *arv)
{
	switch (*arv) {
		case 'D':
			harl.complain("DEBUG"); // No break, to allow fall-through: Al no utilizar break, permite la caída a través de los casos de forma que
									// si se selecciona DEBUG, también se ejecutan INFO, WARNING y ERROR, y asi con cada caso.
		case 'I':
			harl.complain("INFO");
		case 'W':
			harl.complain("WARNING");
		case 'E':
			harl.complain("ERROR");
			break;
		default:
			harl.complain("UNKNOWN");
			break;
	}
}

int main( int arc, char **arv )
{
	if (arc == 2)
	{
		Harl harl;
		checkComplains(harl, arv[1]);
	}
	else
		std::cerr << "Error: Wrong number of arguments" << std::endl;
	return (0);
}