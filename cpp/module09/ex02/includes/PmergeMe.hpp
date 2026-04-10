/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:37 by analba-s          #+#    #+#             */
/*   Updated: 2026/04/10 16:36:04 by analba-s         ###   ########.fr       */
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

		static void			fordJohnsonSortVector( std::vector<int> &vec, int left, int right );
		static void			createPairsVector( const std::vector<int> &vec, int left, int right,
												std::vector<std::pair<int, int> > &pairs, 
												std::vector<int> &unpaired );
		static void			separateWinnersAndLosersVector( const std::vector<std::pair<int, int> > &pairs,
														std::vector<int> &winners,
														std::vector<std::pair<int, int> > &losers_with_bounds );
		static size_t		binarySearchVector( const std::vector<int> &sorted, 
											  int value, size_t end );
			
		static void			fordJohnsonSortDeque( std::deque<int> &deq, int left, int right );
		static void			createPairsDeque( const std::deque<int> &deq, int left, int right,
										  std::deque<std::pair<int, int> > &pairs,
										  std::deque<int> &unpaired );
		static void			separateWinnersAndLosersDeque( const std::deque<std::pair<int, int> > &pairs,
													   std::deque<int> &winners,
													   std::deque<std::pair<int, int> > &losers_with_bounds );
		static size_t		binarySearchDeque( const std::deque<int> &sorted,
											 int value, size_t end );

		static std::vector<size_t>	generateInsertionOrder( size_t n );

};

std::vector<size_t>	generateJacobsthal(int maxValue);

#endif
