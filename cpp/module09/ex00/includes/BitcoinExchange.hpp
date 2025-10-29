/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:39:44 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/29 19:17:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP_
#define BITCOIN_EXCHANGE_HPP_

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

/// @typedef PriceDataMap
/// @brief Type alias for historical Bitcoin price storage.
/// Maps date strings (YYYY-MM-DD) to their corresponding exchange rates.
typedef std::multimap<std::string, double> PriceDataMap;

/// @struct InputEntry
/// @brief Represents a parsed transaction input entry with validation state.
/// Stores date, quantity, validity status, line tracking, and error messages.
struct InputEntry {
  std::string date;           ///< Date in YYYY-MM-DD format.
  double quantity;            ///< Bitcoin quantity for exchange.
  bool is_valid;              ///< True if entry passed all validations.
  int line_index;             ///< Original line number in input file.
  std::string error_message;  ///< Error message if is_valid is false.
};

/// @typedef InputDataMap
/// @brief Type alias for transaction input storage.
/// Maps date strings to InputEntry structures for transaction processing.
typedef std::multimap<std::string, InputEntry> InputDataMap;

/// @class BitcoinExchange
/// @brief Manages Bitcoin price data and computes transaction exchange values.
///
/// This class implements the Orthodox Canonical Form (OCF):
/// - Default constructor for initialization
/// - Copy constructor for deep copying
/// - Copy assignment operator with self-check
/// - Destructor for resource cleanup
///
/// The class loads historical Bitcoin exchange rates from a CSV file and
/// transaction inputs from a user-provided file, validates all data,
/// and outputs computed exchange values with comprehensive error handling.
/// All output respects the original file order of transactions.
class BitcoinExchange {
 public:
  /// @brief Default constructor.
  /// Initializes both price_data_ and input_data_ as empty containers.
  /// @post Both internal containers are cleared and ready for use.
  BitcoinExchange();

  /// @brief Copy constructor.
  /// Performs deep copy of all member variables using STL container copying.
  /// @param other The BitcoinExchange object to copy from.
  /// @pre other is a valid BitcoinExchange instance.
  /// @post This object is an independent copy of other.
  BitcoinExchange(const BitcoinExchange& other);

  /// @brief Copy assignment operator.
  /// Assigns this object's state from another BitcoinExchange instance.
  /// Includes self-assignment check for safety.
  /// @param other The BitcoinExchange object to assign from.
  /// @pre other is a valid BitcoinExchange instance.
  /// @post This object contains independent copies of other's data.
  /// @return Reference to *this for operator chaining.
  BitcoinExchange& operator=(const BitcoinExchange& other);

  /// @brief Destructor.
  /// Automatically deallocates all resources. STL containers handle cleanup.
  /// @post All dynamically allocated memory is released.
  ~BitcoinExchange();

  /// @brief Loads historical Bitcoin price data from a CSV file.
  /// Expected format: "date,exchange_rate" with one entry per line.
  /// The CSV header line (containing "date" and "value") is skipped.
  /// @param file_path Path to the price data CSV file.
  /// @pre file_path points to a readable CSV file with valid format.
  /// @post price_data_ is populated with all valid price entries.
  /// @return true if file loaded successfully; false if file cannot be opened.
  bool LoadPriceData(const std::string& file_path);

  /// @brief Loads transaction input data from a file.
  /// Expected format: "YYYY-MM-DD | quantity" with one per line.
  /// Each entry is validated; invalid entries receive error messages.
  /// @param file_path Path to the transaction input file.
  /// @pre file_path points to a readable file with valid format.
  /// @post input_data_ is populated with all transaction entries (valid/error).
  /// @return true if file loaded successfully; false if file cannot be opened.
  bool LoadInputData(const std::string& file_path);

  /// @brief Processes all loaded transactions and outputs results.
  /// Outputs are printed to stdout in original input file order.
  /// Valid transactions display exchange calculations; invalid ones show errors.
  /// @pre Both price_data_ and input_data_ are populated via Load* methods.
  /// @post Transaction results and error messages printed to stdout.
  void ProcessExchange();

 private:
  /// @brief Historical Bitcoin price data storage.
  /// Maps date strings (YYYY-MM-DD) to exchange rates.
  PriceDataMap price_data_;

  /// @brief Transaction input data storage.
  /// Maps dates to InputEntry structures containing transaction details.
  InputDataMap input_data_;

  /// @brief Parses a single price line from CSV file.
  /// Expected format: "YYYY-MM-DD,price_value"
  /// @param line A single line from the price CSV file.
  /// @param date Output parameter: extracted date if parsing succeeds.
  /// @param price Output parameter: parsed exchange rate if parsing succeeds.
  /// @pre line is non-empty; date and price references are valid.
  /// @post If returns true, date and price contain parsed values.
  /// @return true if line parsed correctly; false for header or malformed data.
  bool ParsePriceLine(const std::string& line, std::string& date,
                      double& price);

  /// @brief Parses a single transaction input line.
  /// Expected format: "YYYY-MM-DD | quantity"
  /// Validates all components and populates entry with results.
  /// @param line A single line from the transaction input file.
  /// @param entry Output parameter: contains parsing results and error state.
  /// @pre line is non-empty; entry reference is valid.
  /// @post entry is fully populated with parse results or error information.
  void ParseInputLine(const std::string& line, InputEntry& entry);

  /// @brief Validates date string format (YYYY-MM-DD).
  /// Checks length and format without attempting value validation.
  /// @param date String to validate as a date.
  /// @pre date is any valid string.
  /// @post No side effects on member variables.
  /// @return true if date matches YYYY-MM-DD format; false otherwise.
  bool IsValidDate(const std::string& date) const;

  /// @brief Validates and converts a string to double.
  /// Ensures entire string is consumed by the conversion (no trailing garbage).
  /// @param str String to convert and validate.
  /// @param value Output parameter: receives parsed double value.
  /// @pre str is any valid string; value reference is valid.
  /// @post If returns true, value contains the parsed number.
  /// @return true if str represents a complete valid double; false otherwise.
  bool IsValidNumber(const std::string& str, double& value) const;

  /// @brief Formats a single output line for exchange results.
  /// Output format: "YYYY-MM-DD => quantity = result"
  /// @param date The transaction date (YYYY-MM-DD).
  /// @param quantity The Bitcoin quantity transacted.
  /// @param price The historical exchange rate for the date.
  /// @pre date is valid YYYY-MM-DD; quantity and price are non-negative.
  /// @post No side effects on member variables.
  /// @return Formatted string ready for output to stdout.
  std::string FormatOutput(const std::string& date, double quantity,
                           double price) const;

  /// @brief Searches for the exchange rate for a given date.
  /// Uses lower_bound for date interpolation: if exact date not found,
  /// returns the rate of the closest earlier date.
  /// @param date The transaction date to search for (YYYY-MM-DD).
  /// @param found Output parameter: set to true if price located.
  /// @pre date is valid YYYY-MM-DD string.
  /// @post found is true if price found or interpolated; false otherwise.
  /// @return Exchange rate for the date, or 0.0 if no earlier date exists.
  double FindPriceForDate(const std::string& date, bool& found) const;

  /// @brief Utility: Removes leading and trailing whitespace.
  /// Returns a trimmed copy without modifying the original string.
  /// @param str String to trim.
  /// @pre str is any valid string.
  /// @post Original str is unchanged; returns trimmed copy.
  /// @return Trimmed string (empty if str contained only whitespace).
  std::string TrimWhitespace(const std::string& str) const;
};

#endif  // BITCOIN_EXCHANGE_HPP_