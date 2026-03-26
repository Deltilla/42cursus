/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:37 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 12:11:19 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cmath>

class PmergeMe
{
	public:
	
		PmergeMe( void );
		PmergeMe( const PmergeMe &copy );
		PmergeMe &operator=( const PmergeMe &copy );
		~PmergeMe();

		void	parseArguments( int argc, char **argv );

		std::vector<int>	_originalSequence;

		static void	sortVector( std::vector<int> &vec );
		static void	sortDeque( std::deque<int> &deq );

	private:

		// ===== VECTOR IMPLEMENTATION =====
		
		// Main Ford-Johnson algorithm for vector
		static void	fordJohnsonSortVector( std::vector<int> &vec, int left, int right );
		
		// Helper: Create pairs from consecutive elements
		static void	createPairsVector( const std::vector<int> &vec, int left, int right,
										std::vector<std::pair<int, int> > &pairs, 
										std::vector<int> &unpaired );
		
		// Helper: Extract winners and losers from pairs
		static void	separateWinnersAndLosersVector( const std::vector<std::pair<int, int> > &pairs,
													std::vector<int> &winners,
													std::vector<int> &losers );
		
		// Helper: Binary search insertion of elements into sorted result
		static void	binaryInsertElementsVector( std::vector<int> &result, 
											   const std::vector<int> &toInsert );
		
		// Helper: Find insertion position using binary search
		static size_t	binarySearchVector( const std::vector<int> &sorted, 
										  int value, size_t end );

		// ===== DEQUE IMPLEMENTATION =====
		
		// Main Ford-Johnson algorithm for deque
		static void	fordJohnsonSortDeque( std::deque<int> &deq, int left, int right );
		
		// Helper: Create pairs from consecutive elements
		static void	createPairsDeque( const std::deque<int> &deq, int left, int right,
									  std::deque<std::pair<int, int> > &pairs,
									  std::deque<int> &unpaired );
		
		// Helper: Extract winners and losers from pairs
		static void	separateWinnersAndLosersDeque( const std::deque<std::pair<int, int> > &pairs,
												   std::deque<int> &winners,
												   std::deque<int> &losers );
		
		// Helper: Binary search insertion of elements into sorted result
		static void	binaryInsertElementsDeque( std::deque<int> &result,
											  const std::deque<int> &toInsert );
		
		// Helper: Find insertion position using binary search
		static size_t	binarySearchDeque( const std::deque<int> &sorted,
										 int value, size_t end );

};

#endif
