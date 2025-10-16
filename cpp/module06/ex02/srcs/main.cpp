/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:47 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/16 20:45:30 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

int main( void )
{
	Base *object = generate();
	Base *objectA = new A;
	Base *bad_object = NULL;
	
	identify(object);
	identify(*object);
	
	identify(objectA);
	identify(*objectA);

	identify(bad_object);
	identify(*bad_object);

	delete object;
	delete objectA;
}