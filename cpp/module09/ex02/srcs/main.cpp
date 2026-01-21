/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 10:00:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

static double getTime( void )
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

int main(int argc, char **argv)
{
	try
	{
		PmergeMe sorter;
		sorter.parseArguments(argc, argv);

		std::vector<int> vectorCopy = sorter._originalSequence;
		std::deque<int> dequeCopy(sorter._originalSequence.begin(), sorter._originalSequence.end());

		// Sort with vector
		double startVector = getTime();
		PmergeMe::sortVector(vectorCopy);
		double endVector = getTime();
		double vectorTime = endVector - startVector;

		// Sort with deque
		double startDeque = getTime();
		PmergeMe::sortDeque(dequeCopy);
		double endDeque = getTime();
		double dequeTime = endDeque - startDeque;

		// Display before
		std::cout << "Before: ";
		for (size_t i = 0; i < sorter._originalSequence.size(); ++i)
		{
			if (i > 0)
				std::cout << " ";
			std::cout << sorter._originalSequence[i];
		}
		std::cout << std::endl;

		// Display after
		std::cout << "After: ";
		for (size_t i = 0; i < vectorCopy.size(); ++i)
		{
			if (i > 0)
				std::cout << " ";
			std::cout << vectorCopy[i];
		}
		std::cout << std::endl;

		// Display time for vector
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << sorter._originalSequence.size()
				  << " elements with std::vector : " << vectorTime << " us" << std::endl;

		// Display time for deque
		std::cout << "Time to process a range of " << sorter._originalSequence.size()
				  << " elements with std::deque : " << dequeTime << " us" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
