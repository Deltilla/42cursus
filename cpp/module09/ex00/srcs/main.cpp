/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:48 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/29 19:17:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

/// @brief Main entry point for Bitcoin exchange calculator.
/// Loads price data and input transactions, then processes exchanges.
/// @param argc Count of command-line arguments (must be 2).
/// @param argv Command-line arguments array. argv[1] should be input file path.
/// @return EXIT_SUCCESS (0) if execution succeeds; EXIT_FAILURE (1) on error.
/// @details
/// - Validates command-line argument count (exactly 1 argument required).
/// - Loads historical Bitcoin prices from "data.csv" in current directory.
/// - Loads transaction inputs from file specified in argv[1].
/// - Processes all transactions and outputs results with error handling.
int main(int argc, char** argv) {
  // Validate correct number of command-line arguments.
  if (argc != 2) {
    std::cerr << "Error: wrong parameters" << std::endl;
    std::cerr << "Usage: ./btc <input_file>" << std::endl;
    return 1;
  }

  // Create Bitcoin exchange processor instance.
  BitcoinExchange exchange;

  // Load historical Bitcoin price data from standard CSV file.
  // Returns false if file cannot be opened.
  if (!exchange.LoadPriceData("data.csv"))
    return 1;

  // Load user-provided transaction input data.
  // Returns false if file cannot be opened.
  if (!exchange.LoadInputData(argv[1]))
    return 1;

  // Process all transactions and output results to stdout.
  exchange.ProcessExchange();

  return 0;
}