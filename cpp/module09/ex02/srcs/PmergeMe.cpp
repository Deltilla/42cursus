/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:41:40 by analba-s          #+#    #+#             */
/*   Updated: 2026/01/21 12:12:20 by analba-s         ###   ########.fr       */
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

		if (*endptr != '\0' || arg.empty())
			throw std::invalid_argument("Error");

		if (val <= 0 || val > 2147483647)
			throw std::invalid_argument("Error");

		_originalSequence.push_back(static_cast<int>(val));
	}
}

size_t PmergeMe::binarySearchVector(const std::vector<int>& sorted, int value, size_t end)
{
	size_t left = 0;
	size_t right = end;
	
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

void PmergeMe::createPairsVector( const std::vector<int> &vec, int left, int right,
									std::vector<std::pair<int, int> > &pairs, 
									std::vector<int> &unpaired )
{
	int i = left;
	while (i <= right)
	{
		if (i + 1 <= right)
		{
			int a = vec[i];
			int b = vec[i + 1];
			if (a < b)
				pairs.push_back(std::make_pair(b, a));
			else
				pairs.push_back(std::make_pair(a, b));
			i += 2;
		}
		else
		{
			unpaired.push_back(vec[i]);
			i++;
		}
	}
}

void PmergeMe::separateWinnersAndLosersVector( const std::vector<std::pair<int, int> > &pairs,
												std::vector<int> &winners,
												std::vector<int> &losers )
{
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		winners.push_back(pairs[j].first);
		losers.push_back(pairs[j].second);
	}
}

void PmergeMe::binaryInsertElementsVector( std::vector<int> &result, 
										   const std::vector<int> &toInsert )
{
	for (size_t j = 0; j < toInsert.size(); ++j)
	{
		size_t pos = binarySearchVector(result, toInsert[j], result.size());
		result.insert(result.begin() + pos, toInsert[j]);
	}
}

void PmergeMe::fordJohnsonSortVector(std::vector<int> &vec, int left, int right)
{
	if (right - left <= 0)
		return;
	
	if (right - left == 1)
	{
		if (vec[right] < vec[left])
			std::swap(vec[left], vec[right]);
		return;
	}

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> unpaired;
	createPairsVector(vec, left, right, pairs, unpaired);

	std::vector<int> winners;
	std::vector<int> losers;
	separateWinnersAndLosersVector(pairs, winners, losers);

	if (!winners.empty())
		fordJohnsonSortVector(winners, 0, winners.size() - 1);

	std::vector<int> result = winners;
	binaryInsertElementsVector(result, losers);
	binaryInsertElementsVector(result, unpaired);

	for (size_t j = 0; j < result.size(); ++j)
		vec[left + j] = result[j];
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	if (vec.empty() || vec.size() == 1)
		return;
	fordJohnsonSortVector(vec, 0, vec.size() - 1);
}

size_t PmergeMe::binarySearchDeque(const std::deque<int>& sorted, int value, size_t end)
{
	size_t left = 0;
	size_t right = end;
	
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

void PmergeMe::createPairsDeque( const std::deque<int> &deq, int left, int right,
								std::deque<std::pair<int, int> > &pairs,
								std::deque<int> &unpaired )
{
	int i = left;
	while (i <= right)
	{
		if (i + 1 <= right)
		{
			int a = deq[i];
			int b = deq[i + 1];
			if (a < b)
				pairs.push_back(std::make_pair(b, a));
			else
				pairs.push_back(std::make_pair(a, b));
			i += 2;
		}
		else
		{
			unpaired.push_back(deq[i]);
			i++;
		}
	}
}

void PmergeMe::separateWinnersAndLosersDeque( const std::deque<std::pair<int, int> > &pairs,
											   std::deque<int> &winners,
											   std::deque<int> &losers )
{
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		winners.push_back(pairs[j].first);
		losers.push_back(pairs[j].second);
	}
}

void PmergeMe::binaryInsertElementsDeque( std::deque<int> &result,
										  const std::deque<int> &toInsert )
{
	for (size_t j = 0; j < toInsert.size(); ++j)
	{
		size_t pos = binarySearchDeque(result, toInsert[j], result.size());
		result.insert(result.begin() + pos, toInsert[j]);
	}
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int> &deq, int left, int right)
{
	if (right - left <= 0)
		return;
	
	if (right - left == 1)
	{
		if (deq[right] < deq[left])
			std::swap(deq[left], deq[right]);
		return;
	}

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> unpaired;
	createPairsDeque(deq, left, right, pairs, unpaired);

	std::deque<int> winners;
	std::deque<int> losers;
	separateWinnersAndLosersDeque(pairs, winners, losers);

	if (!winners.empty())
		fordJohnsonSortDeque(winners, 0, winners.size() - 1);

	std::deque<int> result = winners;
	binaryInsertElementsDeque(result, losers);
	binaryInsertElementsDeque(result, unpaired);

	for (size_t j = 0; j < result.size(); ++j)
		deq[left + j] = result[j];
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	if (deq.empty() || deq.size() == 1)
		return;
	fordJohnsonSortDeque(deq, 0, deq.size() - 1);
}
