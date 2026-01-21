/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:40 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 10:00:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

PmergeMe::PmergeMe( void )
{
}

PmergeMe::PmergeMe( const PmergeMe& copy )
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& copy )
{
	if (this != &copy)
	{
		this->_originalSequence = copy._originalSequence;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseArguments( int argc, char **argv )
{
	if (argc < 2)
		throw std::invalid_argument("Error");

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		char *endptr;
		long val = std::strtol(arg.c_str(), &endptr, 10);

		// Check if the entire string was a valid number
		if (*endptr != '\0' || arg.empty())
			throw std::invalid_argument("Error");

		// Check if the number is positive and within int range
		if (val <= 0 || val > 2147483647)
			throw std::invalid_argument("Error");

		_originalSequence.push_back(static_cast<int>(val));
	}
}

void PmergeMe::mergeInsertSortVector( std::vector<int> &vec, int left, int right )
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSortVector(vec, left, mid);
		mergeInsertSortVector(vec, mid + 1, right);
		mergeVector(vec, left, mid, right);
	}
}

void PmergeMe::mergeVector( std::vector<int> &vec, int left, int mid, int right )
{
	std::vector<int> temp;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
			temp.push_back(vec[i++]);
		else
			temp.push_back(vec[j++]);
	}

	while (i <= mid)
		temp.push_back(vec[i++]);

	while (j <= right)
		temp.push_back(vec[j++]);

	for (size_t k = 0; k < temp.size(); ++k)
		vec[left + k] = temp[k];
}

void PmergeMe::mergeInsertSortDeque( std::deque<int> &deq, int left, int right )
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSortDeque(deq, left, mid);
		mergeInsertSortDeque(deq, mid + 1, right);
		mergeDeque(deq, left, mid, right);
	}
}

void PmergeMe::mergeDeque( std::deque<int> &deq, int left, int mid, int right )
{
	std::deque<int> temp;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (deq[i] <= deq[j])
			temp.push_back(deq[i++]);
		else
			temp.push_back(deq[j++]);
	}

	while (i <= mid)
		temp.push_back(deq[i++]);

	while (j <= right)
		temp.push_back(deq[j++]);

	for (size_t k = 0; k < temp.size(); ++k)
		deq[left + k] = temp[k];
}

void PmergeMe::sortVector( std::vector<int> &vec )
{
	if (vec.empty())
		return;
	mergeInsertSortVector(vec, 0, vec.size() - 1);
}

void PmergeMe::sortDeque( std::deque<int> &deq )
{
	if (deq.empty())
		return;
	mergeInsertSortDeque(deq, 0, deq.size() - 1);
}
