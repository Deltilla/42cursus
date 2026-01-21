/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:37 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 10:00:00 by analba-s         ###   ########.fr       */
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

		// Ford-Johnson algorithm for vector
		static void	mergeInsertSortVector( std::vector<int> &vec, int left, int right );
		static void	mergeVector( std::vector<int> &vec, int left, int mid, int right );

		// Ford-Johnson algorithm for deque
		static void	mergeInsertSortDeque( std::deque<int> &deq, int left, int right );
		static void	mergeDeque( std::deque<int> &deq, int left, int mid, int right );

};

#endif
