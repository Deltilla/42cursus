/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:55 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/16 20:47:57 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>

Base::~Base( void ) {}

Base*	generate( void )
{
	static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
	
	Base* pointer;
	int n = rand() % 3;
	switch (n) {
	case 0:
		pointer = new A;
		break ;
	case 1:
		pointer = new B;
		break ;
	case 2:
		pointer = new C;
		break ;
	}
	return (pointer);
}

void	identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify( Base& p )
{
	try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
	catch (std::exception&) {}
	try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
	catch (std::exception&) {}
	try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
	catch (std::exception&) {}
}