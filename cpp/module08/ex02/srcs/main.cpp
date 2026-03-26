/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 10:58:16 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>

int main()
{
	std::cout << "=== Test 1: Basic operations with integers ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "\n=== Test 2: Forward iteration ===" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "\n=== Test 3: Reverse iteration ===" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}
	
	std::cout << "\n=== Test 4: Const iterator ===" << std::endl;
	const MutantStack<int> cmstack(mstack);
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();
	
	std::cout << "Const iteration: ";
	while (cit != cite) {
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;
	
	std::cout << "\n=== Test 5: MutantStack with strings ===" << std::endl;
	MutantStack<std::string> sstack;
	sstack.push("Hello");
	sstack.push("World");
	sstack.push("!");
	
	MutantStack<std::string>::iterator sit = sstack.begin();
	MutantStack<std::string>::iterator site = sstack.end();
	
	while (sit != site) {
		std::cout << *sit << " ";
		++sit;
	}
	std::cout << std::endl;
	
	std::cout << "\n=== Test 6: Empty check and edge cases ===" << std::endl;
	MutantStack<int> emptyStack;
	std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
	emptyStack.push(42);
	std::cout << "After pushing 42, size: " << emptyStack.size() << std::endl;
	std::cout << "Top: " << emptyStack.top() << std::endl;
	
	std::cout << "\n=== Test 7: Copy constructor and assignment ===" << std::endl;
	MutantStack<int> original;
	original.push(10);
	original.push(20);
	original.push(30);
	
	MutantStack<int> copied(original);
	std::cout << "Copied stack (forward): ";
	for (MutantStack<int>::iterator i = copied.begin(); i != copied.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	MutantStack<int> assigned;
	assigned = original;
	std::cout << "Assigned stack (forward): ";
	for (MutantStack<int>::iterator i = assigned.begin(); i != assigned.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::cout << "\n=== Test 8: Conversion to std::stack ===" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "std::stack size: " << s.size() << std::endl;
	std::cout << "std::stack top: " << s.top() << std::endl;
	
	return 0;
}